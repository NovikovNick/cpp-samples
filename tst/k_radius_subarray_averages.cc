#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/k_radius_subarray_averages.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{7, 4, 3, 9, 1, 8, 5, 2, 6};
  std::vector<int> expected{-1, -1, -1, 5, 4, 4, -1, -1, -1};
  int k = 3;

  // act
  auto res = solution.getAverages(nums, k);

  // assert
  for (int i = 0; i < expected.size(); ++i) {
    // debug("{} ", res[i]);
    BOOST_CHECK_EQUAL(expected[i], res[i]);
  }
  
}
#endif  // !CASE_1
