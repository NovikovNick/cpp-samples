#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/lexicographically_smallest_equivalent_string.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string s1("parker");
  std::string s2("morris");
  std::string baseStr("parser");

  // act
  auto res = solution.smallestEquivalentString(s1, s2, baseStr);

  // assert
  BOOST_CHECK_EQUAL("makkek", res);
}
#endif  // !CASE_1
