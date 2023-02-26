#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 0
#define CASE_2 1
#define CASE_3 0
#define DEBUG 1

#include "../src/leetcode/edit_distance.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.minDistance("ccacaa", "axaxxaa");

  // assert
  BOOST_CHECK_EQUAL(4, res);
}
#endif  // !CASE_1 

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.minDistance("intention", "execution");

  // assert
  BOOST_CHECK_EQUAL(5, res);
}
#endif  // !CASE_2

#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.minDistance("horse", "ros");

  // assert
  BOOST_CHECK_EQUAL(3, res);
}
#endif  // !CASE_3
