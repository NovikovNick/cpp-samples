#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/length-of-the-longest-alphabetical-continuous-substring.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.longestContinuousSubstring("abacaba");

  // assert
  BOOST_CHECK_EQUAL(2, res);
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.longestContinuousSubstring("abcde");

  // assert
  BOOST_CHECK_EQUAL(5, res);
}
