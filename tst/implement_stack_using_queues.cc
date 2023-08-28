#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/implement_stack_using_queues.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange

  // act
  auto obj = std::make_unique<leetcode::MyStack>();
  obj->push(1);
  obj->push(2);
  auto param_3 = obj->top();
  auto param_2 = obj->pop();
  auto param_4 = obj->empty();

  // assert
  BOOST_CHECK_EQUAL(2, param_3);
  BOOST_CHECK_EQUAL(2, param_2);
  BOOST_CHECK(!param_4);
}
#endif  // !CASE_1
