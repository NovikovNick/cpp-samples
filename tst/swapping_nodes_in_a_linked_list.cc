#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/swapping_nodes_in_a_linked_list.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.swapNodes(nullptr, 5);

  // assert
  //BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
