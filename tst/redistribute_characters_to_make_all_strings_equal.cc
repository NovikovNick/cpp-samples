#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/redistribute_characters_to_make_all_strings_equal.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> words{"abc", "aabc", "bc"};

  // act
  bool res = solution.makeEqual(words);

  // assert
  BOOST_CHECK(res);
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> words{"ab", "a"};

  // act
  bool res = solution.makeEqual(words);

  // assert
  BOOST_CHECK(!res);
}