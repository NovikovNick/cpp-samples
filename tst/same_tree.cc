#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/same_tree.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  std::vector<leetcode::TreeNode *> p;
  for (const auto &it : {1, 2, 3}) p.push_back(new leetcode::TreeNode(it));
  for (int i = 0; i < p.size() - 2; ++i) {
    p[i]->left = p[i * 2 + 1];
    p[i]->right = p[i * 2 + 2];
  }

  std::vector<leetcode::TreeNode *> q;
  for (const auto &it : {1, 2, 3, 4}) q.push_back(new leetcode::TreeNode(it));
  for (int i = 0; i < q.size() - 2; ++i) {
    if ((i * 2 + 1) < (q.size())) q[i]->left = q[i * 2 + 1];
    if ((i * 2 + 2) < (q.size())) q[i]->right = q[i * 2 + 2];
  }

  // act
  auto res = solution.isSameTree(p[0], q[0]);

  // assert
  BOOST_CHECK(!res);
}
#endif  // !CASE_1
