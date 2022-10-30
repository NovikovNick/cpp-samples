#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/fin_bottom_left_tree_value.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  leetcode::TreeNode n1(1);
  leetcode::TreeNode n2(2);
  leetcode::TreeNode n3(3);

  n2.left = &n1;
  n2.right = &n3;

  // act
  auto res = solution.findBottomLeftValue(&n2);

  // assert
  BOOST_CHECK_EQUAL(1, res);
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  leetcode::TreeNode n1(1);
  leetcode::TreeNode n2(2);
  leetcode::TreeNode n3(3);
  leetcode::TreeNode n4(4);
  leetcode::TreeNode n5(5);
  leetcode::TreeNode n6(6);
  leetcode::TreeNode n7(7);

  n1.left = &n2;
  n2.left = &n4;
  n1.right = &n3;
  n3.left = &n5;
  n3.right = &n6;
  n5.left = &n7;

  // act
  auto res = solution.findBottomLeftValue(&n1);

  // assert
  BOOST_CHECK_EQUAL(7, res);
}
