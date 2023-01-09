#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/merge_two_sorted_lists.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

void print(leetcode::ListNode* lst) {
  while (lst) {
    debug("{} ", lst->val);
    lst = lst->next;
  }
  debug("\n");
};

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  auto list1 = new leetcode::ListNode(1);
  for (auto it = list1; const auto& num : {2, 3, 4, 5}) {
    it->next = new leetcode::ListNode(num);
    it = it->next;
  }

  auto list2 = new leetcode::ListNode(5);
  for (auto it = list2; const auto& num : {6, 7, 8, 9}) {
    it->next = new leetcode::ListNode(num);
    it = it->next;
  }

  // act
  auto res = solution.mergeTwoLists(list1, list2);

  // assert
  print(res);
}
#endif  // !CASE_1
