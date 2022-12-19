#define BOOST_TEST_MODULE SolutionTest
#define CASE_2 1
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/find_if_path_exists_in_graph.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 10, source = 3, destination = 5;
  std::vector<std::vector<int>> edges{{2, 6}, {4, 7}, {1, 2}, {3, 5}, {7, 9},
                                      {6, 4}, {9, 8}, {0, 1}, {3, 0}};

  // act
  auto res = solution.validPath(n, edges, source, destination);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
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
