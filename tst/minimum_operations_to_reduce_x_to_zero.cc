#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_operations_to_reduce_x_to_zero.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{1, 1, 4, 2, 3};
  int x = 5;

  // act
  auto res = solution.minOperations(nums, x);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1
