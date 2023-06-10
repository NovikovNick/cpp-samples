#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/maximum_value_at_a_given_index_in_a_bounded_array.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 5;
  int index = 3;
  int maxSum = 100;

  // act
  auto res = solution.maxValue(n, index, maxSum);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1
