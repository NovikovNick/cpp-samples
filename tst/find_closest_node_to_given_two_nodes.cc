#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/find_closest_node_to_given_two_nodes.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> edges{4, 4, 8, -1, 9, 8, 4, 4, 1, 1};

  // act
  auto res = solution.closestMeetingNode(edges, 5, 6);

  // assert
  BOOST_CHECK_EQUAL(1, res);
}
#endif  // !CASE_1
