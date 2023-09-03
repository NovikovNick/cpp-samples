#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/unique_paths.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int m = 3, n = 7;
  // act
  auto res = solution.uniquePaths(m, n);

  // assert
  BOOST_CHECK_EQUAL(28, res);
}
#endif  // !CASE_1
