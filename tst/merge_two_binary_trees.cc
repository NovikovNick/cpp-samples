#define BOOST_TEST_MODULE SolutionTest
#define CASE_2 0
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/merge_two_binary_trees.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

void printReqursive(leetcode::TreeNode* node) {
  if (node) {
    debug("{} ", node->val);
    printReqursive(node->left);
    printReqursive(node->right);
  } else {
    debug("null ");
  }
}

void print(leetcode::TreeNode* node) {
  printReqursive(node);
  debug("\n");
}

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<leetcode::TreeNode*> n1, n2;

  for (std::string it : {"1", "2", "null", "3"})
    n1.push_back(it != "null" ? new leetcode::TreeNode(std::stoi(it))
                              : nullptr);

  for (std::string it : {
                    "1", 
               "null", "2", 
      "null", "null", "null", "3"})
    n2.push_back(it != "null" ? new leetcode::TreeNode(std::stoi(it))
                              : nullptr);

  for (int i = 0; i < n1.size(); ++i) {
    if (n1[i]) {
      if (i * 2 + 1 < n1.size()) n1[i]->left = n1[i * 2 + 1];
      if (i * 2 + 2 < n1.size()) n1[i]->right = n1[i * 2 + 2];
    }
  }

  for (int i = 0; i < n2.size(); ++i) {
    if (n2[i]) {
      if (i * 2 + 1 < n2.size()) n2[i]->left = n2[i * 2 + 1];
      if (i * 2 + 2 < n2.size()) n2[i]->right = n2[i * 2 + 2];
    }
  }

  // act
  print(n1[0]);
  print(n2[0]);
  auto res = solution.mergeTrees(n1[0], n2[0]);

  // assert
  print(res);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  auto n1 = new leetcode::TreeNode(1);

  // act
  auto res = solution.mergeTrees(n1, nullptr);

  // assert
  print(res);
}
#endif  // !CASE_2
