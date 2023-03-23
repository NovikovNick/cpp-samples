#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/number_of_operations_to_make_network_connected.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 6;
  std::vector<std::vector<int>> connections = {
      {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};

  // act
  auto res = solution.makeConnected(n, connections);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1
