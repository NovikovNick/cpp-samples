#include <barrier>
#include <chrono>
#include <future>
#include <latch>
#include <thread>
#include <vector>

#include "../util/log.h"

namespace sample_concur {

void print(const std::vector<int>& arr) {
  for (const auto& it : arr) util::debug("{} ", it);
  util::debug("\n");
}

void when_all_sample() {
  using namespace std::chrono_literals;

  // std::latch latch(3);  // can be decremented more then once

  auto on_complete = []() noexcept { util::debug("\n"); };
  std::barrier barrier{3, on_complete};

  std::vector<std::thread> arr;
  for (int i = 0; i < 3; ++i) {
    arr.push_back(std::thread([i, &barrier]() {
      while (true) {
        for (int j = 0; j < 5; ++j) {
          if (j == i) {
            util::debug("{}", i);
          } else {
            barrier.arrive_and_wait();
          }
        }

        /*switch (i) {
          case 1:
            util::debug("{}", i);
            barrier.arrive_and_wait();
            barrier.arrive_and_wait();
            barrier.arrive_and_wait();
            break;
          case 2:
            barrier.arrive_and_wait();
            util::debug("{}", i);
            barrier.arrive_and_wait();
            barrier.arrive_and_wait();
            break;
          case 3:
            barrier.arrive_and_wait();
            barrier.arrive_and_wait();
            util::debug("{}", i);
            barrier.arrive_and_wait();
            break;
        }*/
      }
      return i;
    }));
  }

  for (auto& it : arr) it.join();
}

}  // namespace sample_concur
