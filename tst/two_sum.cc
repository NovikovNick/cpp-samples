#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/two_sum.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  // act
  auto res = solution.twoSum(nums, target);

  // assert
  BOOST_CHECK_EQUAL(0, res[0]);
  BOOST_CHECK_EQUAL(1, res[1]);
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums = {3, 2, 4};
  int target = 6;

  // act
  auto res = solution.twoSum(nums, target);

  // assert
  BOOST_CHECK_EQUAL(1, res[0]);
  BOOST_CHECK_EQUAL(2, res[1]);
}

BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums = {3, 3};
  int target = 6;

  // act
  auto res = solution.twoSum(nums, target);

  // assert
  BOOST_CHECK_EQUAL(0, res[0]);
  BOOST_CHECK_EQUAL(1, res[1]);
}
