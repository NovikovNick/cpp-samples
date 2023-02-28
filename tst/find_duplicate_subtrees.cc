#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define CASE_2 0
#define CASE_3 0
#define DEBUG 1

#include "../src/leetcode/find_duplicate_subtrees.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<leetcode::TreeNode*> nodes;
  std::vector<std::string> data{
                "1", 
        "2",             "3", 
    "4",    "*",     "2",    "4", 
  "*","*","*","*", "4","3","*","*",
  };
  for (std::string& num : data) {
    leetcode::TreeNode* n =
        num == "*" ? nullptr : new leetcode::TreeNode(std::stoi(num));
    nodes.push_back(n);
  }

  for (int i = 0; i < nodes.size() - 2; ++i) {
    if (nodes[i] == nullptr) continue;
    if (2 * i + 1 < nodes.size() && nodes[2 * i + 1])
      nodes[i]->left = nodes[2 * i + 1];
    if (2 * i + 2 < nodes.size() && nodes[2 * i + 2])
      nodes[i]->right = nodes[2 * i + 2];
  }

  // act
  auto res = solution.findDuplicateSubtrees(nodes[0]);
  debug("{}\n", res.size());
  // assert
  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<leetcode::TreeNode*> nodes;
  std::vector<std::string> data{ "2", "1", "1"};
  for (std::string& num : data) {
    leetcode::TreeNode* n =
        num == "*" ? nullptr : new leetcode::TreeNode(std::stoi(num));
    nodes.push_back(n);
  }

  for (int i = 0; i < nodes.size() - 2; ++i) {
    if (nodes[i] == nullptr) continue;
    if (2 * i + 1 < nodes.size() && nodes[2 * i + 1])
      nodes[i]->left = nodes[2 * i + 1];
    if (2 * i + 2 < nodes.size() && nodes[2 * i + 2])
      nodes[i]->right = nodes[2 * i + 2];
  }

  // act
  auto res = solution.findDuplicateSubtrees(nodes[0]);
  debug("{}\n", res.size());
  // assert
  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_2


#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<leetcode::TreeNode*> nodes;
  std::vector<std::string> data{
          "1", 
      "2",    "2", 
    "3","*","3","*"
  };
  for (std::string& num : data) {
    leetcode::TreeNode* n =
        num == "*" ? nullptr : new leetcode::TreeNode(std::stoi(num));
    nodes.push_back(n);
  }

  for (int i = 0; i < nodes.size() - 2; ++i) {
    if (nodes[i] == nullptr) continue;
    if (2 * i + 1 < nodes.size() && nodes[2 * i + 1])
      nodes[i]->left = nodes[2 * i + 1];
    if (2 * i + 2 < nodes.size() && nodes[2 * i + 2])
      nodes[i]->right = nodes[2 * i + 2];
  }

  // act
  auto res = solution.findDuplicateSubtrees(nodes[0]);
  debug("{}\n", res.size());
  // assert
  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_3