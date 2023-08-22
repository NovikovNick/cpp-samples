#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/excel_sheet_column_title.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act & assert
  for (int column = 1; column < 30; ++column) {
    debug("{} -> {}\n\n", solution.convertToTitle(column), column);
  }
}
#endif  // !CASE_1
