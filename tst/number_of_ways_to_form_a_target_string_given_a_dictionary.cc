#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/number_of_ways_to_form_a_target_string_given_a_dictionary.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> words = {"acca", "bbbb", "caca"};
  std::string target = "aba";
  // act
  auto res = solution.numWays(words, target);

  // assert
  BOOST_CHECK_EQUAL(6, res);
}
#endif  // !CASE_1
