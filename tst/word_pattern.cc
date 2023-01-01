#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/word_pattern.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  //std::string pattern = "zbbz", s = "dog cat cat dog";
  std::string pattern = "zbbz", s = "dog dog dog dog";

  // act
  auto res = solution.wordPattern(pattern, s);

  // assert
  BOOST_CHECK(!res);
}
#endif  // !CASE_1
