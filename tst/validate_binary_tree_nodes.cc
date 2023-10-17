#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/validate_binary_tree_nodes.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 4;
  std::vector<int> leftChild = {1, -1, 3, -1};
  std::vector<int> rightChild = {2, -1, -1, -1};
  
  // act
  auto res = solution.validateBinaryTreeNodes(n, leftChild, rightChild);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
