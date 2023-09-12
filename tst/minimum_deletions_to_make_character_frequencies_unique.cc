#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_deletions_to_make_character_frequencies_unique.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string str = "ceabaacb";

  // act
  auto res = solution.minDeletions(str);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1
