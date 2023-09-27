#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/decoded_string_at_index.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string s = "leet2code3";

  // act
  auto res = solution.decodeAtIndex(s, 10);

  // assert
  BOOST_CHECK_EQUAL("o", res);
}
#endif  // !CASE_1
