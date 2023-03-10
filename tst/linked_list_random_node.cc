#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/linked_list_random_node.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  std::vector<leetcode::ListNode*> nodes(4);
  for (int i = 0; i < nodes.size(); ++i) {
    nodes[i] = new leetcode::ListNode(i);
    if (i > 0) nodes[i - 1]->next = nodes[i];
  }
  leetcode::Solution solution(nodes[0]);
  
  // act & assert
  for (int i = 0; i < 10; ++i) {
    debug("{} \n", solution.getRandom());
  }
}
#endif  // !CASE_1
