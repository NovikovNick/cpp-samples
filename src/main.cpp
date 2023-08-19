#define DEBUG

#include <templates.h>

#include <bit>
#include <bitset>
#include <cstdint>
#include <numeric>

#include "cpp_features/common.h"
#include "util/log.h"

class String {
  char* data_;
  size_t size_;
  size_t capacity;

 public:
  // TODO: copy ctor
  // TODO: copy assignment
};

/*

struct A {
  int data;

  A() : A(0){};

  A(const int num) : data(num) { util::debug("{} ctor\n", data); };

  A(const A& a) : data(a.data) { util::debug("copy ctor\n"); }

  A& operator=(const A& a) {
    util::debug("copy assignment\n");
    data = a.data;
    return *this;
  }

  A(A&& other) noexcept : data(other.data) {
    util::debug("move ctor\n");
    other.data = 0;
  }

  A& operator=(A&& a) noexcept {
    util::debug("move assignment\n");
    data = a.data;
    a.data = 0;
    return *this;
  }

  ~A() { util::debug("dtor {}\n", data); };

  static A getA() {
    A res;
    return res;  // NRVO
  }
};

*/

int main([[maybe_unused]] int argc, [[maybe_unused]] char argv[]) {
  templates::MyArray<std::string, 5>{}.Print();
  templates::MyArray<double, 5>{}.Print();

  return 0;
}
