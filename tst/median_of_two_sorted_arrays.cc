#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/median_of_two_sorted_arrays.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums1{1, 2};
  std::vector<int> nums2{3, 4};

  // act
  auto res = solution.findMedianSortedArrays(nums1, nums2);

  // assert
  BOOST_CHECK_EQUAL(2.5, res);
}
#endif  // !CASE_1
