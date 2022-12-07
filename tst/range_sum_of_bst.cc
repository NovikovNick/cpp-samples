#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/range_sum_of_bst.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  auto n10 = new leetcode::TreeNode(10);
  auto n5 = new leetcode::TreeNode(5);
  auto n15 = new leetcode::TreeNode(15);
  auto n3 = new leetcode::TreeNode(3);
  auto n7 = new leetcode::TreeNode(7);
  auto n18 = new leetcode::TreeNode(18);
  auto root = n10;
  n10->left = n5;
  n10->right = n15;
  n5->left = n3;
  n5->right = n7;
  n15->right = n18;

  // act
  auto res = solution.rangeSumBST(root, 7, 15);

  // assert
  BOOST_CHECK_EQUAL(32, res);
}
#endif  // !CASE_1
