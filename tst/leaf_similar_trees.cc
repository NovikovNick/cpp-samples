#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/leaf_similar_trees.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  auto n1 = new leetcode::TreeNode(1);
  auto n2 = new leetcode::TreeNode(2);
  auto n3 = new leetcode::TreeNode(3);

  n1->left = n2;
  n1->right = n3;

  // act
  auto res = solution.leafSimilar(n1, n1);

  // assert
  BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
