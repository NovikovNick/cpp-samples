#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/interleaving_string.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string s1 = "aabcc";
  std::string s2 = "dbbca";
  std::string s3 = "aadbbcbcac";

  // act
  auto res = solution.isInterleave(s1, s2, s3);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
