#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/shortest_path_with_alternating_colors.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 3;
  std::vector<std::vector<int>> redEdges{{0, 1}, {1, 2}};
  std::vector<std::vector<int>> blueEdges{};
  // act
  auto res = solution.shortestAlternatingPaths(n, redEdges, blueEdges);

  // assert
  std::vector<int> expected{0, 1, -1};
  for (int i = 0; i < n; ++i) {
    debug("{} ", res[i]);
    BOOST_CHECK_EQUAL(expected[i], res[i]);
  }
  debug("\n");
}
#endif  // !CASE_1
