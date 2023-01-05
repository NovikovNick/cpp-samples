#include <thread>

#include "../util/log.h"

namespace concurrency {

void hello() { std::cout << "It works..." << std::endl; }

void run() {
  int x = 100000;
  while (--x > 0) {
    util::debug("{}.\n", x);
  }
}

struct ThreadGuard {
  std::thread& t;

  ThreadGuard(std::thread& t) : t(t){};
  ~ThreadGuard() {
    if (t.joinable()) t.join();
  }

  ThreadGuard(const ThreadGuard&) = delete;
  ThreadGuard& operator=(const ThreadGuard&) = delete;
};


/*
simple alternative for the std::jthread from the CXX20
*/
struct ScopedGuard {
  std::thread t_;
  ScopedGuard(std::thread t) : t_(std::move(t)) {
    if (!t_.joinable()) throw new std::logic_error("No thread!");
  }
  ~ScopedGuard() {
    if (t_.joinable()) t_.join();
  }

  ScopedGuard(const ScopedGuard&) = delete;
  ScopedGuard& operator=(const ScopedGuard&) = delete;
};
}  // namespace concurrency