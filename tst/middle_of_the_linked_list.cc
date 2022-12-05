#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/middle_of_the_linked_list.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  auto root = new leetcode::ListNode(1);
  auto curr = root;
  for (int i = 2; i <= 3; ++i) {
    auto next = new leetcode::ListNode(i);
    curr->next = next;
    curr = next;
  }
  leetcode::Solution solution;

  // act
  auto res = solution.middleNode(root);

  // assert
  BOOST_CHECK_EQUAL(2, res->val);
}
#endif  // !CASE_1
