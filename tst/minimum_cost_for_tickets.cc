#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 0
#define CASE_2 1
#define DEBUG 1

#include "../src/leetcode/minimum_cost_for_tickets.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> days{1, 4, 6, 7, 8, 20};
  std::vector<int> costs{2, 7, 15};
  // act
  auto res = solution.mincostTickets(days, costs);

  // assert
  BOOST_CHECK_EQUAL(11, res);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> days{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
  std::vector<int> costs{2, 7, 15};
  // act
  auto res = solution.mincostTickets(days, costs);

  // assert
  BOOST_CHECK_EQUAL(17, res);
}
#endif  // !CASE_2
