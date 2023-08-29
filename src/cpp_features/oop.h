#ifndef CPP_FEATURES_OOP_H
#define CPP_FEATURES_OOP_H

#include "../util/log.h"

namespace oop {
class Base {
 public:
  virtual void foo() = 0;
  Base() {
    util::debug("[{:^5s}]:... ctor\n", "Base");
    // foo();
  };

  virtual ~Base() {
    util::debug("[{:^5s}]:... dtor\n", "Base");
    // foo();
  };
};

class A : virtual public Base {
 public:
  A() {
    util::debug("[{:^5s}]:... ctor\n", "A");
    foo();
  };
  ~A() {
    util::debug("[{:^5s}]:... dtor\n", "A");
    foo();
  };
  virtual void foo() override { util::debug("[{:^5s}]:... foo\n", "A"); }
};

class B : virtual public Base {
 public:
  B() {
    util::debug("[{:^5s}]:... ctor\n", "B");
    foo();
  };
  ~B() {
    util::debug("[{:^5s}]:... dtor\n", "B");
    foo();
  };
  virtual void foo() override { util::debug("[{:^5s}]:... foo\n", "B"); }
};

class C : public A, public B {
 public:
  C() {
    util::debug("[{:^5s}]:... ctor\n", "C");
    foo();
  };
  ~C() {
    util::debug("[{:^5s}]:... dtor\n", "C");
    foo();
  };
  virtual void foo() override { util::debug("[{:^5s}]:... foo\n", "C"); }
  // virtual void bar() { util::debug("[{:^5s}]:... bar\n", "C"); }
};

void sample() {
  util::debug("[oop]:... Base {} polymorphic\n",
              std::is_polymorphic<Base>{}.value  //
                  ? "is"
                  : "is NOT");
  util::debug("[oop]:... A {} polymorphic\n",
              std::is_polymorphic<A>{}.value  //
                  ? "is"
                  : "is NOT");

  /*A obj;
  Base& base_ref = obj;
  Base* base_ptr = new A{};
  base_ref.foo();
  base_ptr->foo();
  delete base_ptr;*/

  /*C c;
  c.A::foo();
  c.B::foo();
  c.foo();*/
  C c;
  util::debug("[oop]:... B size = {} bytes\n", sizeof(B));
}
}  // namespace oop

#endif  // CPP_FEATURES_OOP_H