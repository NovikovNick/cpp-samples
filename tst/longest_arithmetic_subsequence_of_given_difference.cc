#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/longest_arithmetic_subsequence_of_given_difference.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> arr{1, 5, 7, 8, 5, 3, 4, 2, 1};
  int diff = -2;

  // act
  auto res = solution.longestSubsequence(arr, diff);

  // assert
  BOOST_CHECK_EQUAL(4, res);
}
#endif  // !CASE_1
