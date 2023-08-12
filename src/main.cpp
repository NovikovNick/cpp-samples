#define DEBUG

#include <format>

#include "util/log.h"
#include "cpp_features/fold.h"

struct A {
  int data;
  A(int i) : data(i) { util::debug("constructor {}\n", data); }

  A(const A& other) {
    data = other.data;
    util::debug("copy constructor {}\n", data);
  }

  A(const A&& other) noexcept {
    data = other.data;
    util::debug("move constructor {}\n", data);
  }

  ~A() { util::debug("destructor {}\n", data); }
};

A getA() {
  A a1{1};
  return (A{2}, A{3});
}


int main([[maybe_unused]] int argc, [[maybe_unused]] char argv[]) {
  fold::sample();
  return 0;
}
