#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/maximal_network_rank.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> roads{{4, 6}, {5, 2}, {3, 5}, {7, 5}, {7, 6}};
  int n = 8;

  // act
  auto res = solution.maximalNetworkRank(n, roads);

  // assert
  BOOST_CHECK_EQUAL(5, res);
}
#endif  // !CASE_1
