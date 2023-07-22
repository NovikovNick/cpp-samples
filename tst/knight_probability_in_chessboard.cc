#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#include "../src/leetcode/knight_probability_in_chessboard.cc"

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 3, k = 2, row = 0, column = 0;

  // act
  auto res = solution.knightProbability(n, k, row, column);

  // assert
  BOOST_CHECK_EQUAL(0.06250, res);
}
#endif  // !CASE_1
