#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_absolute_difference_in_bst.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<leetcode::TreeNode*> nodes{new leetcode::TreeNode(0),
                                         new leetcode::TreeNode(1),
                                         new leetcode::TreeNode(2),
                                         new leetcode::TreeNode(3),
                                         new leetcode::TreeNode(4),
                                         new leetcode::TreeNode(5),
                                         new leetcode::TreeNode(6)};

  nodes[4]->left = nodes[2];
  nodes[4]->right= nodes[6];
  nodes[2]->left = nodes[1];
  nodes[2]->right = nodes[3];
  // act
  auto res = solution.getMinimumDifference(nodes[4]);

  // assert
  BOOST_CHECK_EQUAL(1, res);
}
#endif  // !CASE_1
