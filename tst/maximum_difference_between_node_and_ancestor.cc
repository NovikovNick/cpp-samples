#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/maximum_difference_between_node_and_ancestor.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  auto n8 = new leetcode::TreeNode(8);
  auto n3 = new leetcode::TreeNode(3);
  auto n1 = new leetcode::TreeNode(1);
  auto n6 = new leetcode::TreeNode(6);
  auto n4 = new leetcode::TreeNode(4);
  auto n7 = new leetcode::TreeNode(7);
  auto n10 = new leetcode::TreeNode(10);
  auto n14 = new leetcode::TreeNode(14);
  auto n13 = new leetcode::TreeNode(13);
  
  n8->left = n3;
  n8->right = n10;

  n3->left = n1;
  n3->right = n6;
  
  n6->left = n4;
  n6->right = n7;

  n10->right = n14;
  n14->left = n13;

  auto root = n8;
  // act
  auto res = solution.maxAncestorDiff(root);

  // assert
  BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
