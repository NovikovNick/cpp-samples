#include <cassert>

#include "cpp_features/common.h"
#include "cpp_features/explicit_conversion.h"
#include "util/log.h"

class Base {
 public:
  virtual void foo() = 0;
  virtual ~Base() = default;
};

class Derived : Base {
  mutable int x;

 public:
  void changeX() const { x = 42; }
  virtual void foo() override { util::debug("[Derived]:... foo\n"); }
};



int main([[maybe_unused]] int argc, [[maybe_unused]] char argv[]) {
  explicit_conversion::sample();
  return 0;
}
