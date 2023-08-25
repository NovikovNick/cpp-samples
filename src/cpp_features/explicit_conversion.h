#ifndef CPP_FEATURES_EXPLICIT_CONVERSION_H
#define CPP_FEATURES_EXPLICIT_CONVERSION_H

#include <cassert>

#include "../util/log.h"

namespace explicit_conversion {
struct A {
  int data;

  // support implicit conversion, add explicit to disable implicit conversion
  A(const int val) : data(val){};

  void print() { util::debug("[A]:... data: {}\n", data); };

  operator int() const { return data; }  // support explicit conversion
};
void sample() {
  A obj = 42;  // implicit conversions
  const A& const_ref = obj;

  // a.print(); // error: not a const method
  const_cast<A&>(const_ref).print();

  int explicit_converted_obj = static_cast<int>(obj);  // explicit type conversion
  auto c_style_explicit_converted_obj = (const int&)obj;

  assert(42 == explicit_converted_obj);
  assert(42 == c_style_explicit_converted_obj);
};
};  // namespace explicit_conversion

#endif  // CPP_FEATURES_EXPLICIT_CONVERSION_H