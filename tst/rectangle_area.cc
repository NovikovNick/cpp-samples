#define BOOST_TEST_MODULE SolutionTest
#define CASE_2 1
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/rectangle_area.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;
  // act
  auto res = solution.computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);

  // assert
  BOOST_CHECK_EQUAL(45, res);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  int ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2,
      by2 = 2;
  // act
  auto res = solution.computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);

  // assert
  BOOST_CHECK_EQUAL(16, res);
}
#endif  // !CASE_1