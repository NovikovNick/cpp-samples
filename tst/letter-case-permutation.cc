#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/letter-case-permutation.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.letterCasePermutation("a1b2");

  // assert
  BOOST_CHECK(std::find(res.cbegin(), res.cend(), "a1b2") != res.end());
  BOOST_CHECK(std::find(res.cbegin(), res.cend(), "a1B2") != res.end());
  BOOST_CHECK(std::find(res.cbegin(), res.cend(), "A1b2") != res.end());
  BOOST_CHECK(std::find(res.cbegin(), res.cend(), "A1B2") != res.end());
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.letterCasePermutation("3z4");

  // assert
  BOOST_CHECK(std::find(res.cbegin(), res.cend(), "3z4") != res.end());
  BOOST_CHECK(std::find(res.cbegin(), res.cend(), "3Z4") != res.end());
}
