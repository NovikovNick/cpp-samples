#define BOOST_TEST_MODULE SolutionTest
#define CASE_2 1
#define CASE_1 0
#define DEBUG 1

#include "../src/leetcode/sort_list.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::list<int> nums{2, 1, 3, 5, 6, 7, 3, 12, 4, 8, 9, 12, 3, 43, 55, 64};
  auto list1 = new leetcode::ListNode(4);
  for (auto it = list1; const auto& num : nums) {
    it->next = new leetcode::ListNode(num);
    it = it->next;
  }

  // act
  auto res = solution.sortList(list1);

  // assert
  while (res && res->next) {
    BOOST_CHECK(res->val <= res->next->val);
    debug("{} - {}\n", res->val, res->next->val);
    res = res->next;
  }
}
#endif  // !CASE_

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;

  std::list<int> nums(1000);
  std::iota(nums.begin(), nums.end(), 2);
  auto list1 = new leetcode::ListNode(1);
  for (auto it = list1; const auto& num : nums) {
    it->next = new leetcode::ListNode(num);
    it = it->next;
  }

  // act
  auto t0 = std::chrono::steady_clock::now();
  auto res = solution.sortList(list1);
  auto t1 = std::chrono::steady_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0);

  // assert
  int expected_size = nums.size() + 1;
  int actual_size = 1;
  while (res && res->next) {
    BOOST_CHECK(res->val <= res->next->val);
    res = res->next;
    ++actual_size;
  }
  BOOST_CHECK_EQUAL(actual_size, expected_size);
  debug("Elapsed {}ms\n", elapsed.count());
}
#endif  // !CASE_2
