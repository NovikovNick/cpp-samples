#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/scramble_string.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string s1("great"), s2("rgeat");
  
  // act
  auto res = solution.isScramble(s1, s2);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
