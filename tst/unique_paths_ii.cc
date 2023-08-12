#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/unique_paths_ii.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> grid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

  // act
  auto res = solution.uniquePathsWithObstacles(grid);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1
