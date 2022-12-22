#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/sum_of_distances_in_tree.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> edges{{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};

  // act
  auto res = solution.sumOfDistancesInTree(edges.size() + 1, edges);

  // assert
  std::vector<int> expected{8, 12, 6, 10, 10, 10};
  for (int i = 0; i < expected.size(); ++i)
    BOOST_CHECK_EQUAL(expected[i], res[i]);
}
#endif  // !CASE_1