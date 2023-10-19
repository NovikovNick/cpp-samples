#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/backspace_string_compare.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string s = "ab#c", t = "ad#c";

  // act
  auto res = solution.backspaceCompare(s, t);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
