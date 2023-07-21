#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/number_of_longest_increasing_subsequence.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{1, 3, 5, 4, 7};

  // act
  auto res = solution.findNumberOfLIS(nums);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1
