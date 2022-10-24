#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/determine_if_string_halves_are_alike.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string s("book");

  // act
  auto res = solution.halvesAreAlike(s);

  // assert
  BOOST_CHECK(res);
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::string s("textbook");

  // act
  auto res = solution.halvesAreAlike(s);

  // assert
  BOOST_CHECK(!res);
}
