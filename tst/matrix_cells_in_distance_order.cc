#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/matrix_cells_in_distance_order.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int rows = 2, cols = 3, rCenter = 1, cCenter = 2;

  // act
  auto res = solution.allCellsDistOrder(rows, cols, rCenter, cCenter);

  // assert
  //  BOOST_CHECK_EQUAL(42, res);
  for (const auto it : res) debug("[{}, {}] ", it[0], it[1]);
  debug("\n");
}
#endif  // !CASE_1
