#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/evaluate_the_bracket_pairs_of_a_string.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string s("(name)is(age)yearsold");
  std::vector<std::vector<std::string>> knowledge{{"name", "bob"},
                                                  {"age", "two"}};
    // act
    auto res = solution.evaluate(s, knowledge);

    // assert
    BOOST_CHECK_EQUAL("", res);
  }
#endif  // !CASE_1
