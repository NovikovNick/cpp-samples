#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/maximum_number_of_vowels_in_a_substring_of_given_length.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string s = "abciiidef";
  int k = 3;
  // act
  auto res = solution.maxVowels(s, k);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}
#endif  // !CASE_1
