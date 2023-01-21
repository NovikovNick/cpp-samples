#ifndef SNAKE_SAMPLE_H_
#define SNAKE_SAMPLE_H_

#include <chrono>
#include <thread>

#include "../util/log.h"
#include "game_state.h"

namespace ggpo {

struct Callbacks {
  bool(__cdecl *save_game_state)(unsigned char **buffer, int *len,
                                 int *checksum, int frame);
  bool(__cdecl *load_game_state)(unsigned char *buffer, int len);
};

class Launcher {
  Callbacks cb;

 public:
  Launcher(const Callbacks &cb) : cb(cb) {}

  /*
    ggpo::Callbacks cb{0};
    cb.load_game_state = ggpo::loadGameState;
    cb.save_game_state = ggpo::saveGameState;
    ggpo::Launcher(cb).start();
  */
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

  GameAPI() : gs(GameState{}) {}

  bool saveGS(unsigned char **buffer, int *len, int *checksum, int frame) {
    GameState new_gs;
    new_gs.status = frame;

    util::debug("Save: {:3d}. size {} ", new_gs.status, sizeof(new_gs));

    *len = sizeof(new_gs);
    *buffer = new unsigned char[*len];
    memcpy(*buffer, &new_gs, sizeof(new_gs));
    return true;
  };

  bool loadGS(unsigned char *buffer, int len) {
    auto begin = buffer;
    memcpy(&gs, begin, sizeof(gs));
    util::debug("Load:{:3d}\n", gs.status, len);
    return true;
  };
};

bool saveGameState(unsigned char **buffer, int *len, int *checksum, int frame) {
  return GameAPI::instance().saveGS(buffer, len, checksum, frame);
}

bool loadGameState(unsigned char *buffer, int len) {
  return GameAPI::instance().loadGS(buffer, len);
}
}  // namespace ggpo
#endif  // SNAKE_SAMPLE_H_