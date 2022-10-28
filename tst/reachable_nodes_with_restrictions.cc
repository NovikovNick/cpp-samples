#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/reachable_nodes_with_restrictions.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 7;
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {3, 1},
                                         {4, 0}, {0, 5}, {5, 6}};
  std::vector<int> restricted = {4, 5};

  // act
  auto res = solution.reachableNodes(7, edges, restricted);

  // assert
  BOOST_CHECK_EQUAL(4, res);
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  int n = 7;
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {0, 5},
                                         {0, 4}, {3, 2}, {6, 5}};
  std::vector<int> restricted = {4, 2, 1};

  // act
  auto res = solution.reachableNodes(7, edges, restricted);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}
