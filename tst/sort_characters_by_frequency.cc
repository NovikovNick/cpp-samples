#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/sort_characters_by_frequency.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string s("loveleetcode");
  // act
  auto res = solution.frequencySort(s);

  // assert
  BOOST_CHECK_EQUAL("eeeeoollvtdc", res);
}
#endif  // !CASE_1
