#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/palindrome_partitioning.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.partition("aabcb");

  // assert
  for (const auto& partition : res) {
    for (const auto& palindrome : partition) {
      debug("{}. ", palindrome);
    }
    debug("\n");
  }
}
#endif  // !CASE_1
