#define BOOST_TEST_MODULE SolutionTest
#define CASE_2 1
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/valid_sudoku.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std ::vector<char>> board{
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  // act
  auto res = solution.isValidSudoku(board);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std ::vector<char>> board{
      {'.', '.', '.', '9', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '3', '.', '.', '.', '.', '.', '1'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'1', '.', '.', '.', '.', '.', '3', '.', '.'},
      {'.', '.', '.', '.', '2', '.', '6', '.', '.'},
      {'.', '9', '.', '.', '.', '.', '.', '7', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'8', '.', '.', '8', '.', '.', '.', '.', '.'}};

  // act
  auto res = solution.isValidSudoku(board);

  // assert
  BOOST_CHECK(!res);
}
#endif  // !CASE_1