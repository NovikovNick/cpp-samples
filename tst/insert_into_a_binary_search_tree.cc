#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/insert_into_a_binary_search_tree.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

void printInInorderTraversal(leetcode::TreeNode* node) {
  if (!node) return;
  printInInorderTraversal(node->left);
  debug("{} ", node->val);
  printInInorderTraversal(node->right);
};

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  std::vector<std::string> vals{"4", "2", "7", "1", "3"};
  std::vector<leetcode::TreeNode*> nodes(vals.size(), nullptr);

  for (int i = 0; i < vals.size(); ++i)
    if (vals[i] != "null")
      nodes[i] = new leetcode::TreeNode(std::stoi(vals[i]));

  for (int i = 0; (i * 2 + 2) < vals.size(); ++i) {
    if (nodes[i]) {
      nodes[i]->left = nodes[i * 2 + 1];
      nodes[i]->right = nodes[i * 2 + 2];
    }
  }

  // act
  auto res = solution.insertIntoBST(nodes[0],-11);

  // assert
  printInInorderTraversal(res);
}
#endif  // !CASE_1
