#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/delete_node_in_a_linked_list.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  //
  std::vector<int> src{4, 5, 1, 9};
  std::vector<leetcode::ListNode*> lst;

  for (const auto& it : src) lst.push_back(new leetcode::ListNode(it));
  for (int i = 0; i < src.size() - 1; ++i) lst[i]->next = lst[i + 1];

  // act
  solution.deleteNode(lst[1]);

  // assert
  auto it = lst[0];
  while (it) {
    debug("{}\n", it->val);
    it = it->next;
  }
}
#endif  // !CASE_1
