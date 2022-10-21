#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/minimum_time_visiting_all_points.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> points = {
      {1, 1},
      {3, 4},
      {-1, 0},
  };

  // act
  auto res = solution.minTimeToVisitAllPoints(points);

  // assert
  BOOST_CHECK_EQUAL(7, res);
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> points = {
      {3, 2},
      {-2, 2}
  };

  // act
  auto res = solution.minTimeToVisitAllPoints(points);

  // assert
  BOOST_CHECK_EQUAL(5, res);
}
