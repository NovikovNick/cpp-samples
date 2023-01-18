#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/maximum_sum_circular_subarray.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{5, -1, 5};
  // act
  auto res = solution.maxSubarraySumCircular(nums);

  // assert
  BOOST_CHECK_EQUAL(10, res);
}
#endif  // !CASE_1
