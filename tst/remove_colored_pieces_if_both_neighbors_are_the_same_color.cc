#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/remove_colored_pieces_if_both_neighbors_are_the_same_color.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.winnerOfGame("AAAABBBB");

  // assert
  BOOST_CHECK(!res);
}
#endif  // !CASE_1
