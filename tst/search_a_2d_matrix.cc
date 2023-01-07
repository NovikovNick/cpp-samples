#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/search_a_2d_matrix.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> matrix{
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

  // act

  // assert
  for (const auto& row : matrix)
    for (const auto& col : row) BOOST_CHECK(solution.searchMatrix(matrix, col));

  BOOST_CHECK(!solution.searchMatrix(matrix, -1));
  BOOST_CHECK(!solution.searchMatrix(matrix, 2));
  BOOST_CHECK(!solution.searchMatrix(matrix, 4));
  BOOST_CHECK(!solution.searchMatrix(matrix, 6));
  BOOST_CHECK(!solution.searchMatrix(matrix, 8));
  BOOST_CHECK(!solution.searchMatrix(matrix, 12));
  BOOST_CHECK(!solution.searchMatrix(matrix, 14));
  BOOST_CHECK(!solution.searchMatrix(matrix, 17));
  BOOST_CHECK(!solution.searchMatrix(matrix, 21));
  BOOST_CHECK(!solution.searchMatrix(matrix, 25));
  BOOST_CHECK(!solution.searchMatrix(matrix, 31));
  BOOST_CHECK(!solution.searchMatrix(matrix, 35));
  BOOST_CHECK(!solution.searchMatrix(matrix, 66));
}
#endif  // !CASE_1
