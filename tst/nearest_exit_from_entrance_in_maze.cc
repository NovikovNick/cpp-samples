#define BOOST_TEST_MODULE SolutionTest
#define CASE_4 1
#define CASE_3 1
#define CASE_2 1
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/nearest_exit_from_entrance_in_maze.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<char>> maze{
      {'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};

  std::vector<int> entrance{1, 2};
  // act
  auto res = solution.nearestExit(maze, entrance);

  // assert
  BOOST_CHECK_EQUAL(1, res);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<char>> maze{
      {'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}};

  std::vector<int> entrance{1, 0};
  // act
  auto res = solution.nearestExit(maze, entrance);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_2

#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<char>> maze{{'.', '+'}};

  std::vector<int> entrance{0, 0};
  // act
  auto res = solution.nearestExit(maze, entrance);

  // assert
  BOOST_CHECK_EQUAL(-1, res);
}
#endif  // !CASE_3

#if CASE_4
BOOST_AUTO_TEST_CASE(case4) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<char>> maze{
      {'.', '.', '.', '.', '.', '+', '.', '.', '.'},
      {'.', '+', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '+', '.', '+', '.', '+', '.', '+'},
      {'.', '.', '.', '.', '+', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '+', '+', '.', '.', '.'},
      {'+', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '+', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '+', '.', '.', '.', '.', '+'},
      {'+', '.', '.', '+', '.', '+', '+', '.', '.'}};

  std::vector<int> entrance{8, 4};
  // act
  auto res = solution.nearestExit(maze, entrance);

  // assert
  BOOST_CHECK_EQUAL(5, res);
}
#endif  // !CASE_3
