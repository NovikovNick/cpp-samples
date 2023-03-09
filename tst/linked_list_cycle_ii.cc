#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/linked_list_cycle_ii.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<leetcode::ListNode*> nodes;
  int n = 10;
  for (int i = 0; i < n; ++i) {
    nodes.push_back(new leetcode::ListNode(i));
    if (i > 0) nodes[i - 1]->next = nodes[i];
  }

  // act

  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < n; ++i) {
      if (i > 0) nodes[i - 1]->next = nodes[i];
    }
    nodes[n - 1]->next = nodes[j];
    debug("{:2d}. ", j);
    solution.detectCycle(nodes[0]);
    debug("\n");
  }
}
#endif  // !CASE_1
