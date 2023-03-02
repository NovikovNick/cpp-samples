#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/string_compression.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<char> chars{'a', 'b', 'b', 'c', 'c', 'c'};

  // act
  auto res = solution.compress(chars);

  // assert
  for (int i = 0; i < res; ++i) {
    debug("{}", chars[i]);
  }
  debug("\n");
}
#endif  // !CASE_1
