#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/symmetric_tree.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> val{"1", "2", "2", "3", "null", "null", "3"};
  std::vector<leetcode::TreeNode*> nodes(val.size(), nullptr);
  for (int i = 0; i < val.size(); ++i)
    if ("null" != val[i]) nodes[i] = new leetcode::TreeNode(std::stoi(val[i]));

  for (int i = 0; (i * 2 + 2) < val.size(); ++i) {
    if (nodes[i]) {
      nodes[i]->left = nodes[i * 2 + 1];
      nodes[i]->right = nodes[i * 2 + 2];
    }
  }

  // act
  auto res = solution.isSymmetric(nodes[0]);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
