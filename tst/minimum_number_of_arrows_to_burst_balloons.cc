#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_number_of_arrows_to_burst_balloons.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> points{{10, 16}, {2, 8}, {1, 6}, {7, 12}};

  // act
  auto res = solution.findMinArrowShots(points);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1
