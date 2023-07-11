#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/all_nodes_distance_k_in_binary_tree.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.distanceK(nullptr, nullptr, 0);

  // assert
  // BOOST_CHECK_EQUAL(0, res.size());
}
#endif  // !CASE_1
