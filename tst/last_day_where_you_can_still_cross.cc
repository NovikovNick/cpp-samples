#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/last_day_where_you_can_still_cross.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int row = 2;
  int col = 2;
  std::vector<std::vector<int>> cells{{1, 1}, {2, 1}, {1, 2}, {2, 2}};

  // act
  auto res = solution.latestDayToCross(row, col, cells);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1
