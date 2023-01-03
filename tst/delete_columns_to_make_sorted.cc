#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/delete_columns_to_make_sorted.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> strs{"rrjk", "furt", "guzm"};

  // act
  auto res = solution.minDeletionSize(strs);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1
