#define BOOST_TEST_MODULE SolutionTest
#define CASE_7 1
#define CASE_6 1
#define CASE_5 1
#define CASE_4 1
#define CASE_3 1
#define CASE_2 1
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/basic_calculator.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.calculate("1 + 1");

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.calculate("-1");

  // assert
  BOOST_CHECK_EQUAL(-1, res);
}
#endif  // !CASE_2

#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.calculate("2147483647");

  // assert
  BOOST_CHECK_EQUAL(2147483647, res);
}
#endif  // !CASE_3

#if CASE_4
BOOST_AUTO_TEST_CASE(case4) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.calculate("(((-5)))");

  // assert
  BOOST_CHECK_EQUAL(-5, res);
}
#endif  // !CASE_4

#if CASE_5
BOOST_AUTO_TEST_CASE(case5) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.calculate("(1+(4+5+2)-3)+(6+8)");

  // assert
  BOOST_CHECK_EQUAL(23, res);
}
#endif  // !CASE_5

#if CASE_6
BOOST_AUTO_TEST_CASE(case6) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.calculate(" 2-1 + 2 ");

  // assert
  BOOST_CHECK_EQUAL(3, res);
}
#endif  // !CASE_6

#if CASE_7
BOOST_AUTO_TEST_CASE(case7) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.calculate("-2+1");

  // assert
  BOOST_CHECK_EQUAL(-1, res);
}
#endif  // !CASE_5