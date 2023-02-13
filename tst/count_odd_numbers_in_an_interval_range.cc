#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/count_odd_numbers_in_an_interval_range.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.countOdds(3,7);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}
#endif  // !CASE_1
