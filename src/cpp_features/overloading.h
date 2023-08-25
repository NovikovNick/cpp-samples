#ifndef CPP_FEATURES_OVERLOADING_H
#define CPP_FEATURES_OVERLOADING_H

#include "../util/log.h"

namespace overloading {

class B {
  // ...
 public:
  void Foo(int x) { util::debug("[B]:... int x = {}\n", x); };
};
class D : public B {
  // ...
 public:
  using B::Foo;
  void Foo(double x) { util::debug("[D]:... double x = {}\n", x); };
};


void foo(int x) { util::debug("[overloading]:... int\n"); };
void foo(float x) { util::debug("[overloading]:... float\n"); };

void sample() {
  // void foo(float x); 
  // foo(1.0f);

  D d;
  d.Foo(2.0);
}
}  // namespace overloading

#endif  // CPP_FEATURES_OVERLOADING_H