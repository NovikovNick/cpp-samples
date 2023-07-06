#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_size_subarray_sum.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int target = 7;
  std::vector<int> nums{2, 3, 1, 2, 4, 3};
  
  // act
  auto res = solution.minSubArrayLen(target, nums);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1
