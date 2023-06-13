#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/equal_row_and_column_pairs.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> grid{{3, 1, 2, 2},  //
                                     {1, 4, 4, 5},  //
                                     {2, 4, 2, 2},  //
                                     {2, 4, 2, 2}};

  // act
  auto res = solution.equalPairs(grid);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}
#endif  // !CASE_1
