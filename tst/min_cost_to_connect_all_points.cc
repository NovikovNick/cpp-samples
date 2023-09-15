#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/min_cost_to_connect_all_points.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> points{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};

  // act
  auto res = solution.minCostConnectPoints(points);

  // assert
  BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
