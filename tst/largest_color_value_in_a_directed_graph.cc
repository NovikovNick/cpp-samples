#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/largest_color_value_in_a_directed_graph.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string colors("rrrde");
  std::vector<std::vector<int>> edges{{4, 2}, {3, 4}, {0, 3}, {1, 0}, {2, 1}};

  // act
  auto res = solution.largestPathValue(colors, edges);

  // assert
  BOOST_CHECK_EQUAL(-1, res);
}
#endif  // !CASE_1
