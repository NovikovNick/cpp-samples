#ifndef CPP_FEATURES_SEPARATE_DUPLICATE_METHODS_H
#define CPP_FEATURES_SEPARATE_DUPLICATE_METHODS_H

#include <cassert>

#include "../util/log.h"

namespace separate_duplicate_methods {

struct BaseA {
  virtual void duplicateMethod() { util::debug("[BaseA]:... duplicate A\n"); }
};
struct BaseA2 : BaseA {
  virtual void duplicateAMethod() = 0;

 private:
  virtual void duplicateMethod() override { duplicateAMethod(); }
};

struct BaseB {
  virtual void duplicateMethod() { util::debug("[BaseB]:... duplicate B\n"); }
};
struct BaseB2 : BaseB {
  virtual void duplicateBMethod() = 0;

 private:
  virtual void duplicateMethod() override { duplicateBMethod(); }
};

struct C : BaseA2, BaseB2 {
private:
  void duplicateAMethod() { util::debug("[  C  ]:... A\n"); }
  void duplicateBMethod() { util::debug("[  C  ]:... B\n"); }
};

void sample() {
  C c;
  BaseA& a = c;
  BaseB& b = c;

  // c.foo();
  a.duplicateMethod();
  b.duplicateMethod();
}
}  // namespace separate_duplicate_methods

#endif  // CPP_FEATURES_SEPARATE_DUPLICATE_METHODS_H