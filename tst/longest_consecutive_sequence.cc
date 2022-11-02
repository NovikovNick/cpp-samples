#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/longest_consecutive_sequence.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums = {100, 4, 200, 1, 3, 2};

  // act
  auto res = solution.longestConsecutive(nums);

  // assert
  BOOST_CHECK_EQUAL(4, res);
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

  // act
  auto res = solution.longestConsecutive(nums);

  // assert
  BOOST_CHECK_EQUAL(9, res);
}
