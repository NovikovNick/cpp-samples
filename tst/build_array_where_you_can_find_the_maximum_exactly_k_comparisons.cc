#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/build_array_where_you_can_find_the_maximum_exactly_k_comparisons.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 2, m = 3, k = 1;

  // act
  auto res = solution.numOfArrays(n, m, k);

  // assert
  BOOST_CHECK_EQUAL(6, res);
}
#endif  // !CASE_1
