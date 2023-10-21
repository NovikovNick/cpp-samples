#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/constrained_subsequence_sum.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums = { 10, 2, -10, 5, 20 };
  int k = 2;

  // act
  auto res = solution.constrainedSubsetSum(nums, k);

  // assert
  BOOST_CHECK_EQUAL(37, res);
}
#endif  // !CASE_1
