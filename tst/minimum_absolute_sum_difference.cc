#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/minimum_absolute_sum_difference.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums1 = {1, 7, 5};
  std::vector<int> nums2 = {2, 3, 5};

  // act
  auto res = solution.minAbsoluteSumDiff(nums1, nums2);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums1 = {2, 4, 6, 8, 10};
  std::vector<int> nums2 = {2, 4, 6, 8, 10};

  // act
  auto res = solution.minAbsoluteSumDiff(nums1, nums2);

  // assert
  BOOST_CHECK_EQUAL(0, res);
}


BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums1 = {1, 10, 4, 4, 2, 7};
  std::vector<int> nums2 = {9,  3, 5, 1, 7, 4};

  // act
  auto res = solution.minAbsoluteSumDiff(nums1, nums2);

  // assert
  BOOST_CHECK_EQUAL(20, res);
}
