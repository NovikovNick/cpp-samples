#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/reverse_linked_list.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{1, 2, 3, 4};
  auto list1 = new leetcode::ListNode(nums[0]);
  auto it = list1;
  for (int i = 1; i < nums.size(); ++i) {
    it->next = new leetcode::ListNode(nums[i]);
    it = it->next;
  }

  // act
  auto res = solution.reverseList(list1);

  // assert
  while (res) {
    debug("{} ", res->val);
    res = res->next;
  }
}
#endif  // !CASE_1
