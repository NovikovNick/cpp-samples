#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/binary_tree_level_order_traversal.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<leetcode::TreeNode*> nodes;
  int n = 10;
  for (int i = 0; i < n; ++i) nodes.push_back(new leetcode::TreeNode(i));

  for (int i = 0; (i * 2 + 2) < n; ++i) {
    nodes[i]->left = nodes[i * 2 + 1];
    nodes[i]->right = nodes[i * 2 + 2];
  }

  // act
  auto res = solution.levelOrder(nodes[0]);

  // assert
  for (const auto& level : res) {
    for (const auto& node : level) {
      debug("{} ", node);
    }
    debug("\n");
  }
}
#endif  // !CASE_1
