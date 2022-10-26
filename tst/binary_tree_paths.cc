#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/binary_tree_paths.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  leetcode::TreeNode n1{1};
  leetcode::TreeNode n2{2};
  leetcode::TreeNode n3{3};
  leetcode::TreeNode n4{5};

  n1.left = &n2;
  n1.right = &n3;
  n2.right = &n4;

  // act
  auto res = solution.binaryTreePaths(&n1);

  // assert
  BOOST_CHECK_EQUAL("1->2->5", res[0]);
  BOOST_CHECK_EQUAL("1->3", res[1]);
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  leetcode::TreeNode n1{1};

  // act
  auto res = solution.binaryTreePaths(&n1);

  // assert
  BOOST_CHECK_EQUAL("1", res[0]);
}
