#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define CASE_2 1
#define CASE_3 1
#define DEBUG 1

#include "../src/leetcode/maximum_69_number.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.maximum69Number(9669);

  // assert
  BOOST_CHECK_EQUAL(9969, res);
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.maximum69Number(9996);

  // assert
  BOOST_CHECK_EQUAL(9999, res);
}
#endif  // !CASE_2

#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.maximum69Number(9999);

  // assert
  BOOST_CHECK_EQUAL(9999, res);
}
#endif  // !CASE_3
