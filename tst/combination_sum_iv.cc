#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/combination_sum_iv.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{1, 2, 3};
  int target = 4;

  // act
  auto res = solution.combinationSum4(nums, target);

  // assert
  BOOST_CHECK_EQUAL(7, res);
}
#endif  // !CASE_1
