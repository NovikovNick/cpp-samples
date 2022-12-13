#define BOOST_TEST_MODULE SolutionTest
#define CASE_2 1
#define CASE_1 0
#define DEBUG 1

#include "../src/leetcode/surrounded_regions.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<char>> board{{'X', 'X', 'X', 'X'},
                                       {'X', 'O', 'O', 'X'},
                                       {'X', 'X', 'O', 'X'},
                                       {'X', 'O', 'X', 'X'}};

  // act
  solution.solve(board);

  // assert
  for (const auto &row : board) {
    for (const auto it : row) debug("{} ", it);
    debug("\n");
  }
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<char>> board{{'O', 'X', 'X', 'O', 'X'},
                                       {'X', 'O', 'O', 'X', 'O'},
                                       {'X', 'O', 'X', 'O', 'X'},
                                       {'O', 'X', 'O', 'O', 'O'},
                                       {'X', 'X', 'O', 'X', 'O'}};

  // act
  solution.solve(board);

  // assert
  for (const auto &row : board) {
    for (const auto it : row) debug("{} ", it);
    debug("\n");
  }
}
#endif  // !CASE_2
