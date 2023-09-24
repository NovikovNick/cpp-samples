#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/champagne_tower.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int poured = 1;
  int query_row = 1;
  int query_glass = 1;

  // act
  auto res = solution.champagneTower(poured, query_row, query_glass);

  // assert
  BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
