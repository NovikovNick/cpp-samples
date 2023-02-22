#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 0
#define CASE_2 1
#define DEBUG 1

#include "../src/leetcode/capacity_to_ship_packages_within_d_days.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;

  std::vector<int> weights{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // act
  auto res = solution.shipWithinDays(weights, 5);

  // assert
  BOOST_CHECK_EQUAL(15, res);
}
#endif  // !CASE_

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  std::vector<int> weights(5e4, 1);
  // act
  auto res = solution.shipWithinDays(weights, 1);

  // assert
  BOOST_CHECK_EQUAL(5e4, res);
}
#endif  // !CASE_1
