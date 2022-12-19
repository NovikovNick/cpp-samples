#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/find_if_path_exists_in_graph.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 3, source = 0, destination = 2;
  std::vector<std::vector<int>> edges{{0, 1}, {1, 2}, {2, 0}};

  // act
  auto res = solution.validPath(n, edges, source, destination);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
