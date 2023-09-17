#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/shortest_path_visiting_all_nodes.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> graph{{1, 2, 3}, {0}, {0}, {0}};

  // act
  auto res = solution.shortestPathLength(graph);

  // assert
  BOOST_CHECK_EQUAL(4, res);
}
#endif  // !CASE_1
