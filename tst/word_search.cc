#define BOOST_TEST_MODULE SolutionTest
#define CASE_3 1
#define CASE_2 1
#define CASE_1 1
#define DEBUG 0

#include "../src/leetcode/word_search.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<char>> board{
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

  // act
  auto res = solution.exist(board, "ABCCED");

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<char>> board{
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

  // act
  auto res = solution.exist(board, "SEE");

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1


#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<char>> board{
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

  // act
  auto res = solution.exist(board, "ABCB");

  // assert
  BOOST_CHECK(!res);
}
#endif  // !CASE_1