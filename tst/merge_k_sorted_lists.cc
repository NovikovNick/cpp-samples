#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/merge_k_sorted_lists.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> nums{{-10, -6, -4, -4, 0, 2, 2, 2, 2},
                                     {-5, 1, 3, 4, 4, 4},
                                     {-9},
                                     {-9},
                                     {-10, -8, -5, -4, -3, -3, -2, 4},
                                     {-10, -8, -7, -4, -4, 0, 1, 2},
                                     {-8, -1, 4},
                                     {-6, -5, -2, -2, -1, 1, 3, 4}};
  std::vector<leetcode::ListNode*> nodes;
  for (const auto& set : nums) {
    auto root = new leetcode::ListNode(set[0]);
    auto curr = root;
    for (int i = 1; i < set.size(); ++i) {
      curr->next = new leetcode::ListNode(set[i]);
      curr = curr->next;
    }
    nodes.push_back(root);
  }

  // act
  auto res = solution.mergeKLists(nodes);

  // assert
  while (res) {
    debug("{} ", res->val);
    res = res->next;
  }
  debug("\n");
}
#endif  // !CASE_1
