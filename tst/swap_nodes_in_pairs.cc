#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/swap_nodes_in_pairs.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

void print(leetcode::ListNode* node) {
  while (node) {
    debug("{} ", node->val);
    node = node->next;
  }
  debug("\n");
}

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  auto n1 = new leetcode::ListNode(1);
  auto n2 = new leetcode::ListNode(2);
  auto n3 = new leetcode::ListNode(3);
  auto n4 = new leetcode::ListNode(4);
  auto n5 = new leetcode::ListNode(5);
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  print(n1);
  // act
  auto res = solution.swapPairs(n1);
  print(res);

  // assert
  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
