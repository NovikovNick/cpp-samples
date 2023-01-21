#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 2
#define CASE_2 1
#define DEBUG 1

#include "../src/leetcode/n_queens_ii.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.totalNQueens(5);

  // assert
  BOOST_CHECK_EQUAL(10, res);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.totalNQueens(4);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_2
