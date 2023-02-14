#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/add_binary.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string a = "11", b = "1";
  // act
  auto res = solution.addBinary(a, b);

  // assert
  BOOST_CHECK_EQUAL("100", res);
}
#endif  // !CASE_1
