#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/letter_combinations_of_a_phone_number.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string digits = "23";
  
  // act
  auto res = solution.letterCombinations(digits);

  // assert
  for (const auto& combination : res) {
    debug("{} \n", combination);
  }
}
#endif  // !CASE_1
