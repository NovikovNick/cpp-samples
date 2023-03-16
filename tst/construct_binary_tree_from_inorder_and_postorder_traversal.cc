#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 0
#define CASE_2 0
#define CASE_3 0
#define CASE_4 1
#define DEBUG 1

#include "../src/leetcode/construct_binary_tree_from_inorder_and_postorder_traversal.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

void buildPostorder(leetcode::TreeNode* node, std::vector<int>& out) {
  if (node == nullptr) return;
  buildPostorder(node->left, out);
  buildPostorder(node->right, out);
  out.push_back(node->val);
}

void buildInorder(leetcode::TreeNode* node, std::vector<int>& out) {
  if (node == nullptr) return;
  buildPostorder(node->left, out);
  out.push_back(node->val);
  buildPostorder(node->right, out);
}


#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<leetcode::TreeNode*> nodes;
  for (int i = 0; i < 10; ++i) nodes.push_back(new leetcode::TreeNode(i));

  nodes[0]->left = nodes[1];
  nodes[1]->left = nodes[2];
  nodes[2]->left = nodes[3];
  nodes[0]->right = nodes[4];
  nodes[4]->right = nodes[5];
  nodes[5]->right = nodes[6];

  std::vector<int> inorder, postorder;
  buildInorder(nodes[0], inorder);
  for (const auto it : inorder) debug("{} ", it);
  debug("\n");

  buildPostorder(nodes[0], postorder);
  for (const auto it : postorder) debug("{} ", it);
  debug("\n");

  // act
  auto res = solution.buildTree(inorder, postorder);

  // assert
  std::vector<int> res_inorder, res_postorder;
  buildInorder(res, res_inorder);
  for (const auto it : res_inorder) debug("{} ", it);
  debug("\n");

  buildPostorder(res, res_postorder);
  for (const auto it : res_postorder) debug("{} ", it);
  debug("\n");

  for (int i = 0; i < inorder.size(); ++i) {
    BOOST_CHECK_EQUAL(res_inorder[i], inorder[i]);
    BOOST_CHECK_EQUAL(res_postorder[i], postorder[i]);
  }
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<leetcode::TreeNode*> nodes;
  for (int i = 0; i < 10; ++i) nodes.push_back(new leetcode::TreeNode(i));

  nodes[0]->left = nodes[1];
  nodes[1]->left = nodes[2];
  nodes[2]->left = nodes[3];
  nodes[3]->right = nodes[4];
  nodes[4]->right = nodes[5];
  nodes[5]->right = nodes[6];

  std::vector<int> inorder, postorder;
  buildInorder(nodes[0], inorder);
  for (const auto it : inorder) debug("{} ", it);
  debug("\n");

  buildPostorder(nodes[0], postorder);
  for (const auto it : postorder) debug("{} ", it);
  debug("\n");

  // act
  auto res = solution.buildTree(inorder, postorder);

  // assert
  std::vector<int> res_inorder, res_postorder;
  buildInorder(res, res_inorder);
  for (const auto it : res_inorder) debug("{} ", it);
  debug("\n");

  buildPostorder(res, res_postorder);
  for (const auto it : res_postorder) debug("{} ", it);
  debug("\n");

  for (int i = 0; i < inorder.size(); ++i) {
    BOOST_CHECK_EQUAL(res_inorder[i], inorder[i]);
    BOOST_CHECK_EQUAL(res_postorder[i], postorder[i]);
  }
}
#endif  // !CASE_2


#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<leetcode::TreeNode*> nodes;
  for (int i = 0; i < 10; ++i) nodes.push_back(new leetcode::TreeNode(i));

  nodes[0]->right = nodes[1];
  nodes[1]->right = nodes[2];
  nodes[2]->right = nodes[3];
  nodes[3]->left = nodes[4];
  nodes[4]->left = nodes[5];
  nodes[5]->left = nodes[6];

  std::vector<int> inorder, postorder;
  buildInorder(nodes[0], inorder);
  for (const auto it : inorder) debug("{} ", it);
  debug("\n");

  buildPostorder(nodes[0], postorder);
  for (const auto it : postorder) debug("{} ", it);
  debug("\n");

  // act
  auto res = solution.buildTree(inorder, postorder);

  // assert
  std::vector<int> res_inorder, res_postorder;
  buildInorder(res, res_inorder);
  for (const auto it : res_inorder) debug("{} ", it);
  debug("\n");

  buildPostorder(res, res_postorder);
  for (const auto it : res_postorder) debug("{} ", it);
  debug("\n");

  for (int i = 0; i < inorder.size(); ++i) {
    BOOST_CHECK_EQUAL(res_inorder[i], inorder[i]);
    BOOST_CHECK_EQUAL(res_postorder[i], postorder[i]);
  }
}
#endif  // !CASE_3


#if CASE_4
BOOST_AUTO_TEST_CASE(case4) {
  // arrange
  leetcode::Solution solution;
  std::vector<leetcode::TreeNode*> nodes;
  for (int i = 1; i < 4; ++i) nodes.push_back(new leetcode::TreeNode(i));

  nodes[1]->left = nodes[1];
  nodes[1]->left = nodes[2];


  std::vector<int> inorder, postorder;
  buildInorder(nodes[0], inorder);
  for (const auto it : inorder) debug("{} ", it);
  debug("\n");

  buildPostorder(nodes[0], postorder);
  for (const auto it : postorder) debug("{} ", it);
  debug("\n");

  // act
  auto res = solution.buildTree(inorder, postorder);

  // assert
  std::vector<int> res_inorder, res_postorder;
  buildInorder(res, res_inorder);
  for (const auto it : res_inorder) debug("{} ", it);
  debug("\n");

  buildPostorder(res, res_postorder);
  for (const auto it : res_postorder) debug("{} ", it);
  debug("\n");

  for (int i = 0; i < inorder.size(); ++i) {
    BOOST_CHECK_EQUAL(res_inorder[i], inorder[i]);
    BOOST_CHECK_EQUAL(res_postorder[i], postorder[i]);
  }
}
#endif  // !CASE_4