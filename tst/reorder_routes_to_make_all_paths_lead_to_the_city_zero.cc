#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/reorder_routes_to_make_all_paths_lead_to_the_city_zero.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 6;
  std::vector<std::vector<int>> connections{
      {0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};

  // act
  auto res = solution.minReorder(n, connections);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}
#endif  // !CASE_1
