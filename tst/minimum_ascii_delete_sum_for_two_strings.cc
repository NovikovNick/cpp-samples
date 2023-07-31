#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_ascii_delete_sum_for_two_strings.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string s1 = "sea";
  std::string s2 = "eat";

  // act
  auto res = solution.minimumDeleteSum(s1, s2);

  // assert
  BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
