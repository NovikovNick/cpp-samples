#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/zigzag_conversion.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string s("0123456789");
  // act
  auto res = solution.convert(s, 3);

  // assert
  debug("res - {} ", res);
  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
