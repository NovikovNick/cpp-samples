#define BOOST_TEST_MODULE SolutionTest
#define CASE_2 1
#define CASE_1 0
#define DEBUG 1

#include "../src/leetcode/snakes_and_ladders.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std ::vector<int>> board{
      {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1},
      {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};
  // act
  auto res = solution.snakesAndLadders(board);

  // assert
  BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std ::vector<int>> board{{1, 1, -1}, {1, 1, 1}, {-1, 1, 1}};
  // act
  auto res = solution.snakesAndLadders(board);

  // assert
  BOOST_CHECK_EQUAL(-1, res);
}
#endif  // !CASE_2
