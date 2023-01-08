#include <chrono>
#include <future>
#include <thread>
#include <vector>

#include "../util/log.h"

namespace sample_concur {

using namespace std::chrono;
using namespace std::chrono_literals;

void start() {
  using clock = high_resolution_clock;

  auto res = std::async([] {
    clock::time_point t0;
    int i = 0;
    while (true) {
      t0 = clock::now();
      std::this_thread::sleep_until(clock::now() + 5ms);
      auto elapsed = duration_cast<milliseconds>(clock::now() - t0).count();
      util::debug("{}. {}\n", ++i, elapsed);
    }
  });

  // This is the recommended way to wait for condition variables with a time
  // limit if you’re not passing a predicate to wait.
  auto timeout = clock::now() + 1s;
  while (true) {
    auto status = res.wait_until(timeout);
    if (timeout < clock::now() || status == std::future_status::ready) break;
  }
  util::debug("done!\n");
}

class GameLoop {
  using clock = high_resolution_clock;
  using frame = duration<uint64_t, std::ratio<1, 60>>;

  bool running_;
  uint64_t frame_sq;
  const uint8_t player1_velocity, player2_velocity;

 public:
  GameLoop(const uint8_t player1_velocity, const uint8_t player2_velocity)
      : running_(true),
        frame_sq(0),
        player1_velocity(player1_velocity),
        player2_velocity(player2_velocity) {}
  void operator()() {
    auto t0 = clock::now();
    while (running_) {
      // processGameState();
      auto new_frame_sq = duration_cast<frame>(clock::now() - t0).count();
      if (frame_sq != new_frame_sq) {
        frame_sq = new_frame_sq;
        std::string log = std::format("{}. ", frame_sq);
        if (frame_sq % player1_velocity == 0) log.append("player 1 moves ");
        if (frame_sq % player2_velocity == 0) log.append("player 2 moves ");
        util::debug("{}\n", log);
      }
    }
  }
};

void startGameLoop() { std::thread(GameLoop{5, 9}).join(); }

}  // namespace sample_concur
