#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_distance_between_bst_nodes.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<leetcode::TreeNode*> nodes;
  for (const auto num : {4, 2, 6, 1, 3})
    nodes.push_back(new leetcode::TreeNode(num));

  for (int i = 0; i < nodes.size(); ++i) {
    if (i * 2 + 1 < nodes.size()) nodes[i]->left = nodes[i * 2 + 1];
    if (i * 2 + 2 < nodes.size()) nodes[i]->right = nodes[i * 2 + 2];
  }

  // act
  auto res = solution.minDiffInBST(nodes[0]);

  // assert
  BOOST_CHECK_EQUAL(1, res);
}
#endif  // !CASE_1
