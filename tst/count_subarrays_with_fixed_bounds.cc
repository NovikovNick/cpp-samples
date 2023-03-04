#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define CASE_2 1
#define DEBUG 1

#include "../src/leetcode/count_subarrays_with_fixed_bounds.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{1, 1, 1, 1, 1, 3, 1, 1, 1, 4, 5, 1, 1, 3, 1};
  int minK = 1, maxK = 1;

  // act
  auto res = solution.countSubarrays(nums, minK, maxK);

  // assert
  BOOST_CHECK_EQUAL(25, res);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{1, 2, 1, 2, 1, 2, 2};
  int minK = 1, maxK = 2;

  // act
  auto res = solution.countSubarrays(nums, minK, maxK);

  // assert
  BOOST_CHECK_EQUAL(20, res);
}
#endif  // !CASE_1
