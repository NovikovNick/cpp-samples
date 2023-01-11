#define BOOST_TEST_MODULE SolutionTest
#define CASE_2 1
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_time_to_collect_all_apples_in_a_tree.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 7;
  std::vector<std::vector<int>> edges{{0, 1}, {0, 2}, {1, 4},
                                      {1, 5}, {2, 3}, {2, 6}};
  std::vector<bool> hasApple{false, false, true, false, true, true, false};

  // act
  auto res = solution.minTime(n, edges, hasApple);

  // assert
  BOOST_CHECK_EQUAL(8, res);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  int n = 4;
  std::vector<std::vector<int>> edges{{0, 2}, {0, 3}, {1, 2}};
  std::vector<bool> hasApple{false, true, false, false};

  // act
  auto res = solution.minTime(n, edges, hasApple);

  // assert
  BOOST_CHECK_EQUAL(4, res);
}
#endif  // !CASE_1
