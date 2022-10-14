#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/recover-a-tree-from-preorder-traversal.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

template <typename T>
void walkTreeAndPrint(T node, int depth) {


  for (int i = 0; i<depth; ++i) {
    std::cout << "  ";
  }
  std::cout << node->val << std::endl;
  if (node->left != nullptr) {
    walkTreeAndPrint(node->left, depth + 1);
  }
  if (node->right != nullptr) {
    walkTreeAndPrint(node->right, depth + 1);
  }
}

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.recoverFromPreorder("1-2--3--4-5--6--7");

  // assert
  walkTreeAndPrint(res, 0);
  delete res;
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.recoverFromPreorder("1-2--3---4-5--6---7");

  // assert
  walkTreeAndPrint(res, 0);
  delete res;
}

BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.recoverFromPreorder("1-401--349---90--88");

  // assert
  walkTreeAndPrint(res, 0);
  delete res;
}

BOOST_AUTO_TEST_CASE(case4) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.recoverFromPreorder("10-7--6-8--7--6");

  // assert
  walkTreeAndPrint(res, 0);
  delete res;
}
