#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/largest_triangle_area.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> points{{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};

  // act
  auto res = solution.largestTriangleArea(points);

  // assert
  BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
