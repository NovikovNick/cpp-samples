#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/insertion_sort_list.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  auto head = new leetcode::ListNode(4);
  auto curr = head;
  for (const auto& it : {2, 1, 3}) {
    curr->next = new leetcode::ListNode(it);
    curr = curr->next;
  }

  // act
  auto res = solution.insertionSortList(head);

  // assert
  while (res) {
    debug("{} ", res->val);
    res = res->next;
  }
  debug("\n");
}
#endif  // !CASE_1
