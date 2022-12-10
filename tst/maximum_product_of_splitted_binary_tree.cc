#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/maximum_product_of_splitted_binary_tree.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  auto n1 = new leetcode::TreeNode(1);
  auto n2 = new leetcode::TreeNode(2);
  auto n3 = new leetcode::TreeNode(3);
  auto n4 = new leetcode::TreeNode(4);
  auto n5 = new leetcode::TreeNode(5);
  auto n6 = new leetcode::TreeNode(6);
  n1->left = n2;
  n2->left = n4;
  n3->left = n6;
  n1->right = n3;
  n2->right = n5;

  auto root = n1;
  // act
  auto res = solution.maxProduct(root);

  // assert
  BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
