#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/maximum_product_of_three_numbers.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums = {1, 2, 3};

  // act
  auto res = solution.maximumProduct(nums);

  // assert
  BOOST_CHECK_EQUAL(6, res);
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums = {1, 2, 3, 4};

  // act
  auto res = solution.maximumProduct(nums);

  // assert
  BOOST_CHECK_EQUAL(24, res);
}

BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums = {-1, -2, -3};

  // act
  auto res = solution.maximumProduct(nums);

  // assert
  BOOST_CHECK_EQUAL(-6, res);
}

BOOST_AUTO_TEST_CASE(case4) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums = {-100, -98, -1, 2, 3, 4};

  // act
  auto res = solution.maximumProduct(nums);

  // assert
  BOOST_CHECK_EQUAL(39200, res);
}

//