#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_number_of_vertices_to_reach_all_nodes.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 6;
  std::vector<std::vector<int>> edges{{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
  
  // act
  auto res = solution.findSmallestSetOfVertices(n, edges);

  // assert
  for (const auto it : res){
    debug("{} ", it);
  }
  debug("\n");
}
#endif  // !CASE_1
