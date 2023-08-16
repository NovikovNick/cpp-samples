#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/sliding_window_maximum.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{-7, -8, 7, 5, 7, 1, 6, 0};
  int k = 4;

  // act
  auto res = solution.maxSlidingWindow(nums, k);

  // assert
  for (const auto max : res) {
    debug("{} \n", max);
  }
  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
