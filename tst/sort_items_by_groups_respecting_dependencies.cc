#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/sort_items_by_groups_respecting_dependencies.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 8, m = 2;
  std::vector<int> group = {-1, -1, 1, 0, 0, 1, 0, -1 };
  std::vector<std::vector<int>> beforeItems = {{}, {6}, {5}, {6}, {3}, {}, {4}, {}};
  // act
  auto res = solution.sortItems(n, m, group, beforeItems);

  // assert
  //BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
