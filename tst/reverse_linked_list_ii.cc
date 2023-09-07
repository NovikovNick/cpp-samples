#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/reverse_linked_list_ii.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  auto node1 = new leetcode::ListNode{1};
  auto node2 = new leetcode::ListNode{2};
  auto node3 = new leetcode::ListNode{3};
  node1->next = node2;
  node2->next = node3;
  
  // act
  auto res = solution.reverseBetween(node1, 3, 3);

  while (res) {
    debug("{} ", res->val);
    res = res->next;
  }
  debug("\n");
  // assert
  //BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
