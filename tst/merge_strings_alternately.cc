#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/merge_strings_alternately.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string word1("aaaa"), word2("bb"), expected("ababaa");
  
  // act
  auto res = solution.mergeAlternately(word1, word2);

  // assert
  BOOST_CHECK_EQUAL(expected, res);
}
#endif  // !CASE_1
