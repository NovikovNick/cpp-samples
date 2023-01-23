#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/merge_two_binary_trees.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

void print(leetcode::TreeNode* node) {
  if (node) {
    debug("{} ", node->val);
    print(node->left);
    print(node->right);
  }
}

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<leetcode::TreeNode*> n1, n2;

  for (std::string it : {"1", "3", "2", "5"})
    n1.push_back(it != "null" ? new leetcode::TreeNode(std::stoi(it))
                              : nullptr);

  for (std::string it : {"2", "1", "3", "null", "4", "null", "7"})
    n2.push_back(it != "null" ? new leetcode::TreeNode(std::stoi(it))
                              : nullptr);

  for (int i = 0; (i * 2 + 2) < n1.size(); ++i) {
    if (n1[i]) {
      n1[i] = n1[i * 2 + 1];
      n1[i] = n1[i * 2 + 2];
    }
  }

  for (int i = 0; (i * 2 + 2) < n2.size(); ++i) {
    if (n2[i]) {
      n2[i] = n2[i * 2 + 1];
      n2[i] = n2[i * 2 + 2];
    }
  }

  // act
  auto res = solution.mergeTrees(n1[0], n2[0]);

  // assert
  print(res);
}
#endif  // !CASE_1
