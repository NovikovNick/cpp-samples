#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/longest_palindromic_subsequence.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string str("bbabab");

  // act
  auto res = solution.longestPalindromeSubseq(str);

  // assert
  BOOST_CHECK_EQUAL(5, res);
}
#endif  // !CASE_1
