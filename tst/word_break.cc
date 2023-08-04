#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/word_break.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string s = "leetcode";
  std::vector<std::string> dictionary{"leet", "leetco", "de"};

  // act
  auto res = solution.wordBreak(s, dictionary);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
