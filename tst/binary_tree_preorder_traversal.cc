#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/binary_tree_preorder_traversal.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<leetcode::TreeNode*> nodes(7);
  for (int i = 0; i < nodes.size(); ++i)
    nodes[i] = new leetcode::TreeNode(i + 1);
  for (int i = 0; i < 3; ++i) {
    nodes[i]->left = nodes[i * 2 + 1];
    nodes[i]->right = nodes[i * 2 + 2];
  }
  std::vector<int> expected{1, 2, 4, 5, 3, 6, 7};

  // act
  // auto res = solution.preorderTraversal(nodes[0]);
  //auto res = solution.inorderTraversal(nodes[0]);
  // auto res = solution.postorderTraversal(nodes[0]);

  debug("Preorder:  ");
  // for (const auto& it : solution.preorderTraversal(nodes[0])) debug("{} ", it);
  debug("\n");

  debug("Inorder:   ");
  // for (const auto& it : solution.inorderTraversal(nodes[0])) debug("{} ", it);
  debug("\n");

  debug("Postorder: ");
  for (const auto& it : solution.postorderTraversal(nodes[0])) debug("{} ", it);
  debug("\n");

  // assert
  /*for (int i = 0; i < expected.size(); ++i) {
    BOOST_CHECK_EQUAL(expected[i], res[i]);
  }*/
}
#endif  // !CASE_1
