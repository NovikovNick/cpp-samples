#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/integer_to_roman.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int num = 3;

  // act
  auto res = solution.intToRoman(num);

  // assert
  BOOST_CHECK_EQUAL("III", res);
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  int num = 58;

  // act
  auto res = solution.intToRoman(num);

  // assert
  BOOST_CHECK_EQUAL("LVIII", res);
}

BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  int num = 1994;

  // act
  auto res = solution.intToRoman(num);

  // assert
  BOOST_CHECK_EQUAL("MCMXCIV", res);
}
