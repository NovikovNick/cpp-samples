#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/binary_tree_zigzag_level_order_traversal.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<leetcode::TreeNode*> nodes;
  for (const auto num : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
    nodes.push_back(new leetcode::TreeNode(num));
  }
  for (int i = 0; i < nodes.size(); ++i) {
    if (i * 2 + 1 < nodes.size()) nodes[i]->left = nodes[i * 2 + 1];
    if (i * 2 + 2 < nodes.size()) nodes[i]->right = nodes[i * 2 + 2];
  }

  // act
  auto res = solution.zigzagLevelOrder(nodes[0]);

  // assert
  for (const auto& row : res) {
    for (const auto it : row) {
      debug("{} ", it);
    }
    debug("\n");
  }
}
#endif  // !CASE_1
