#ifndef CPP_FEATURES_VIRTUAL_H
#define CPP_FEATURES_VIRTUAL_H

#include <complex>

#include "../util/log.h"

namespace virt {
class Base {
 public:
  virtual void f(int) { util::debug("Base::f(int)\n"); };
  virtual void f(double) { util::debug("Base::f(double)\n"); };
  virtual void g(int i = 10) { util::debug("{}\n", i); };

  virtual ~Base() = default;
};

class Derived : public Base {
 public:
  // using Base::f;
  void f(std::complex<double>) { util::debug("Derived::f(complex)\n"); }; // hiding!
  void g(int i = 20) { util::debug("Derived::g()\n"); };
};

void sample() {
  Base b;
  Derived d;
  Base* pb = new Derived;
  b.f(1.0);
  d.f(1.0);
  pb->f(1.0);
  b.g();
  d.g();
  pb->g();
  delete pb;
}

}  // namespace virt

#endif  // CPP_FEATURES_VIRTUAL_H