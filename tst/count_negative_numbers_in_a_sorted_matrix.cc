#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/count_negative_numbers_in_a_sorted_matrix.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> grid{{4, 3, 2, -1},   //
                                     {3, 2, 1, -1},   //
                                     {1, 1, -1, -2},  //
                                     {-1, -1, -2, -3}};

  // act
  auto res = solution.countNegatives(grid);

  // assert
  BOOST_CHECK_EQUAL(8, res);
}
#endif  // !CASE_1
