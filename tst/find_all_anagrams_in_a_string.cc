#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/find_all_anagrams_in_a_string.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string s("cbaebabacd"), p("abc");
  
  // act
  auto res = solution.findAnagrams(s, p);

  // assert
  for (const auto& index : res) debug("{} ", index);
  debug("\n");
}
#endif  // !CASE_1
