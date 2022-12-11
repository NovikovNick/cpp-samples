#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/binary_tree_maximum_path_sum.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  auto n1 = new leetcode::TreeNode(-10);
  auto n2 = new leetcode::TreeNode(9);
  auto n3 = new leetcode::TreeNode(20);
  auto n4 = new leetcode::TreeNode(15);
  auto n5 = new leetcode::TreeNode(7);
  auto n6 = new leetcode::TreeNode(-100);
  auto n7 = new leetcode::TreeNode(-200);

  n1->left = n2;
  n1->right = n3;
  n3->left = n4;
  n3->right = n5;

  //n5->left = n6;
  //n5->right = n7;

  auto root = n1;
  // act
  auto res = solution.maxPathSum(root);

  // assert
  BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
