#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/odd_even_linked_list.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  auto root = new leetcode::ListNode(1);

  {
    auto curr = root;
    for (int i = 2; i <= 5; ++i) {
      curr->next = new leetcode::ListNode(i);
      curr = curr->next;
    }
  }
  
  // act


  auto res = solution.oddEvenList(root);
  {
    auto curr = res;
    while (curr) {
      std::cout << curr->val << " ";
      curr = curr->next;
    }
  }
  // assert
  BOOST_CHECK_EQUAL(1, res->val);
}
#endif  // !CASE_1
