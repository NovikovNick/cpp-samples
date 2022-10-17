#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/advantage_shuffle.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums1 = {2, 7, 11, 15};
  std::vector<int> nums2 = {1, 10, 4, 11};

  // act
  auto res = solution.advantageCount(nums1, nums2);

  // assert
  for (int i = 0; i < res.size(); ++i) {
    std::cout << res[i] << " ? " << nums2[i] << " = "
              << (res[i] > nums2[i] ? 1 : 0) << std::endl;
  }
  BOOST_CHECK_EQUAL(2, res[0]);
  BOOST_CHECK_EQUAL(11, res[1]);
  BOOST_CHECK_EQUAL(7, res[2]);
  BOOST_CHECK_EQUAL(15, res[3]);
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums1 = {12, 24, 8, 32};
  std::vector<int> nums2 = {13, 25, 32, 11};

  // act
  auto res = solution.advantageCount(nums1, nums2);

  // assert
  for (int i = 0; i < res.size(); ++i) {
    std::cout << res[i] << " ? " << nums2[i] << " = "
              << (res[i] > nums2[i] ? 1 : 0) << std::endl;
  }
  BOOST_CHECK_EQUAL(24, res[0]);
  BOOST_CHECK_EQUAL(32, res[1]);
  BOOST_CHECK_EQUAL(8, res[2]);
  BOOST_CHECK_EQUAL(12, res[3]);
}

BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums1 = {2, 0, 4, 1, 2};
  std::vector<int> nums2 = {1, 3, 0, 0, 2};

  // act
  auto res = solution.advantageCount(nums1, nums2);

  // assert
  for (int i = 0; i < res.size(); ++i) {
    std::cout << res[i] << " ? " << nums2[i] << " = "
              << (res[i] > nums2[i] ? 1 : 0) << std::endl;
  }

  BOOST_CHECK_EQUAL(2, res[0]);
  BOOST_CHECK_EQUAL(0, res[1]);
  BOOST_CHECK_EQUAL(2, res[2]);
  BOOST_CHECK_EQUAL(1, res[3]);
  BOOST_CHECK_EQUAL(4, res[4]);
}
