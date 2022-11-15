#define BOOST_TEST_MODULE SolutionTest
#define CASE_4 1
#define CASE_3 1
#define CASE_2 1
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/count_complete_tree_nodes.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  leetcode::TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
  n1.left = &n2;
  n1.right = &n3;
  n2.left = &n4;
  n2.right = &n5;
  n3.left = &n6;

  // act
  auto res = solution.countNodes(&n1);

  // assert
  BOOST_CHECK_EQUAL(6, res);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.countNodes(nullptr);

  // assert
  BOOST_CHECK_EQUAL(0, res);
}
#endif  // !CASE_2

#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  leetcode::TreeNode n1(1);

  // act
  auto res = solution.countNodes(&n1);

  // assert
  BOOST_CHECK_EQUAL(1, res);
}
#endif  // !CASE_3

#if CASE_4
BOOST_AUTO_TEST_CASE(case4) {
  // arrange
  leetcode::Solution solution;
  leetcode::TreeNode n1(1), n2(2), n3(3);
  n1.left = &n2;
  n1.right = &n3;

  // act
  auto res = solution.countNodes(&n1);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}
#endif  // !CASE_4