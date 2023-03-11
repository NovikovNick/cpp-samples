#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/convert_sorted_list_to_binary_search_tree.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

void inorderTraversal(const leetcode::TreeNode* node) {
  if (node == nullptr) return;
  inorderTraversal(node->left);
  debug("{} ", node->val);
  inorderTraversal(node->right);
}

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<leetcode::ListNode*> nodes;
  for (int i = 0; i < 3; ++i) {
    nodes.push_back(new leetcode::ListNode(i));
    if (i > 0) nodes[i - 1]->next = nodes[i];
  }

  // act
  auto res = solution.sortedListToBST(nodes[0]);
  inorderTraversal(res);
  
  // assert
}
#endif  // !CASE_1
