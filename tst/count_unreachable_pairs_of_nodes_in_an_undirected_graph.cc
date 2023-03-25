#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/count_unreachable_pairs_of_nodes_in_an_undirected_graph.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> edges{{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}};
  int n = 7;

  // act
  auto res = solution.countPairs(n, edges);

  // assert
  BOOST_CHECK_EQUAL(14, res);
}
#endif  // !CASE_1
