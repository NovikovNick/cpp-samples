#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/number_of_nodes_in_the_sub_tree_with_the_same_label.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 7;
  std::vector<std::vector<int>> edges{{0, 1}, {0, 2}, {1, 4},
                                      {1, 5}, {2, 3}, {2, 6}};
  std::string labels("abaedcd");

  std::vector<int> expected{2, 1, 1, 1, 1, 1, 1};

  // act
  auto res = solution.countSubTrees(n, edges, labels);

  // assert
  for (int i = 0; i < n; ++i) BOOST_CHECK_EQUAL(expected[i], res[i]);
}
#endif  // !CASE_1
