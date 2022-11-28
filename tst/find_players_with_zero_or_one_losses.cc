#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/find_players_with_zero_or_one_losses.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> matches{{1, 3},  {2, 3}, {3, 6}, {5, 6},
                                        {5, 7},  {4, 5}, {4, 8}, {4, 9},
                                        {10, 4}, {10, 9}};
  // act
  auto res = solution.findWinners(matches);

  // assert
  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
