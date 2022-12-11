#include <chrono>
#include <thread>

#include "util/log.h"

namespace ggpo {
struct Callbacks {
  bool(__cdecl *save_game_state)(unsigned char **buffer, int *len,
                                 int *checksum, int frame);

  bool(__cdecl *load_game_state)(unsigned char *buffer, int len);
};

struct GameState {
  int foo;
  int bar;
  std::vector<int> arr;
};

class Launcher {
  Callbacks cb;

 public:
  Launcher(const Callbacks &cb) : cb(cb) {}

  void start() {
    int frame = 0;
    unsigned char *buf = nullptr;
    int length;
    while (true) {
      cb.save_game_state(&buf, &length, 0, frame);
      cb.load_game_state(buf, length);

      ++frame;
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  };
};

class GameAPI {
  GameState gs;

 public:
  static GameAPI &instance() {
    static GameAPI _instance;
    return _instance;
  }

  GameAPI() : gs({0}) {}

  bool saveGameState(unsigned char **buffer, int *len, int *checksum,
                     int frame) {
    GameState gs_;
    gs_.arr = {1, 2, 3, 4, 5, 6, 7, 8};
    gs_.foo = frame;
    gs_.bar = 100 - frame;
    util::debug("{:3d}. ", frame);
    *len = sizeof(gs_.bar) + sizeof(gs_.foo) + sizeof(int) * gs_.arr.size();
    *buffer = new unsigned char[*len];

    if (!*buffer) {
      return false;
    }

    auto begin = *buffer;
    memcpy(*buffer, &gs_.bar, sizeof(gs_.bar));

    begin += sizeof(gs_.bar);
    memcpy(begin, &gs_.foo, sizeof(gs_.foo));

    begin += sizeof(gs_.foo);
    memcpy(begin, gs_.arr.data(), sizeof(int) * gs_.arr.size());

    return true;
  };

  bool loadGameState(unsigned char *buffer, int len) {
    auto begin = buffer;
    memcpy(&gs.bar, begin, sizeof(gs.bar));

    begin += sizeof(gs.bar);
    memcpy(&gs.foo, begin, sizeof(gs.foo));

    begin += sizeof(gs.foo);
    int size = (len - sizeof(gs.bar) - sizeof(gs.foo)) / sizeof(int);
    gs.arr.resize(size);
    memcpy(gs.arr.data(), begin, sizeof(int) * size);

    for (const auto &it : gs.arr) util::debug("->{}", it);
    util::debug(" foo={} bar={} length={} \n", gs.foo, gs.bar, len);
    return true;
  };
};

bool saveGameState(unsigned char **buffer, int *len, int *checksum, int frame) {
  return GameAPI::instance().saveGameState(buffer, len, checksum, frame);
}

bool loadGameState(unsigned char *buffer, int len) {
  return GameAPI::instance().loadGameState(buffer, len);
}
}  // namespace ggpo