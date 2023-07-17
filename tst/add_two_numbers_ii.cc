#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/add_two_numbers_ii.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  leetcode::ListNode* lhs = new leetcode::ListNode(1);
  auto curr = lhs;
  for (int i = 2; i < 6; ++i) {
    curr->next = new leetcode::ListNode(i);
    curr = curr->next;
  }

  // act
  auto res = solution.addTwoNumbers(lhs, lhs);

  // assert
  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
