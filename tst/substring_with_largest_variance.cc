#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/substring_with_largest_variance.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string s = "aababbb";

  // act
  auto res = solution.largestVariance(s);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}
#endif  // !CASE_1
