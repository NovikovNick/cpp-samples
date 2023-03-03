#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/find_the_index_of_the_first_occurrence_in_a_string.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string haystack{"butsadbutsad"}, needle{"sad"};

  // act
  auto res = solution.strStr(haystack, needle);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}
#endif  // !CASE_1
