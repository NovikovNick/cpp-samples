#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/stone_game_ii.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> piles{2, 7, 9, 4, 4};
  // std::vector<int> piles{1,2,3,4,5,100};

  // act
  auto res = solution.stoneGameII(piles);

  // assert
  BOOST_CHECK_EQUAL(10, res);
}
#endif  // !CASE_1
