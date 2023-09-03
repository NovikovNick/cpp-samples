#ifndef CPP_FEATURES_CONTROL_POLYMORPHISM_H
#define CPP_FEATURES_CONTROL_POLYMORPHISM_H

#include "../util/log.h"

namespace control_polymorphism {

class Base {
 public:
  virtual void VirtFunc(){};
  virtual ~Base(){};
};

class Derived : private Base {
 public:
  virtual void VirtFunc() override{};

  friend void f1();
};

void SomeFunc(const Base&){};

void f1() {
  Derived d;
  SomeFunc(d);  // conversion from Derived to Base in allowed in f1 
}
void f2() {
  Derived d;
  // SomeFunc(d);  // conversion from Derived to Base in disampled in f2 
}

}  // namespace control_polymorphism

#endif  // CPP_FEATURES_CONTROL_POLYMORPHISM_H