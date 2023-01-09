#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/linked_list_cycle.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  std::vector<int> node_values{1,2};
  int n = node_values.size();
  std::vector<leetcode::ListNode*> nodes(n);
  for (int i = 0; i < n; ++i) nodes[i] = new leetcode::ListNode(i + 1);
  for (int i = 0; i < (n - 1); ++i) nodes[i]->next = nodes[i + 1];
  nodes[n - 1]->next = nodes[1];

  // act
  auto res = solution.hasCycle(nodes[0]);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
