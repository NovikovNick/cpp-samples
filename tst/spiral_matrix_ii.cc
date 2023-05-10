#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/spiral_matrix_ii.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 6;
  // act
  auto res = solution.generateMatrix(n);

  // assert
  for (int row = 0; row < n; ++row) {
    for (int col = 0; col < n; ++col) {
      debug("{:3d} ", res[row][col]);
    }
    debug("\n");
  }
  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
