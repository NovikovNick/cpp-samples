#define BOOST_TEST_MODULE MainSampleCppTest

#include <boost/test/included/unit_test.hpp>

// #include "cpp_features/common.h"
#include <chrono>
#include <deque>

#include "util/log.h"

struct Bot {
  std::deque<int> input;
  std::condition_variable cond;
  std::mutex mtx;
  std::jthread t;
  std::atomic_bool running;

  Bot()
      : running(true),
        t([&cond = this->cond,
           &mtx = this->mtx,
           &input = this->input,
           &running = this->running]() {
          using namespace std::chrono_literals;
          while (running) {
            std::unique_lock lock(mtx);                                      // 1
            cond.wait_for(lock, 1s, [&input]() { return !input.empty(); });  // 2
            int counter = 0;                                                 //
            while (!input.empty()) {                                         // 3
              ++counter;
              input.pop_front();
            }
            util::debug("[q]:...{}\n", counter);
          }
        }) {}

  void add(const int val) {
    std::scoped_lock lock(mtx);  // 1
    input.push_back(val);        // 2
    cond.notify_one();           // 3
  }

  void stop() { running.store(false); }
};

BOOST_AUTO_TEST_CASE(main_case) {
  util::debug("[main]:... start\n");
  /*int x = 27;

  auto a1 = x;
  const auto &a2 = x;
  auto &&a3 = a2;
  auto &&a4 = x;
  auto &&a5 = 27;
  auto a6 = {27};
  auto a7{27};

  const char *const str = "";
  auto a8 = str;

  decltype(a1) d1;
  decltype(a4) d2 = d1;
  decltype((a1)) d3 = d2;

  decltype(auto) d4 = a2;
  auto f = f1();*/


  util::debug("[main]:... end\n");
}
