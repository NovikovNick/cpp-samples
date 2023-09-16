#define BOOST_TEST_MODULE MainSampleCppTest

#include <boost/test/included/unit_test.hpp>
#include <cassert>
#include <memory>

#include "cpp_features/exception_safety.h"
#include "util/log.h"

template <class T>
class A {
 protected:
  T data;
};

template <class T>
class B : private A<T> {
 public:
  void foo() { std::cout << this->data << std::endl; }
};

BOOST_AUTO_TEST_CASE(main_case) {
  util::debug("[main]:... start\n");

  exception_safety::sample();

  util::debug("[main]:... end\n");
}
