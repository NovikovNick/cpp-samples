#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/search_a_2d_matrix_ii.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> matrix{{1, 4, 7, 11, 15},
                                       {2, 5, 8, 12, 19},
                                       {3, 6, 9, 16, 22},
                                       {10, 13, 14, 17, 24},
                                       {18, 21, 23, 26, 30}};
  int target = 5;

  // act
  auto res = solution.searchMatrix(matrix, target);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
