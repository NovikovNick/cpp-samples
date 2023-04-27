#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/bulb_switcher.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act & assert
  for (int i = 0; i < 1e3; ++i) {
    BOOST_CHECK_EQUAL(solution.bulbSwitchBruteforce(i), solution.bulbSwitch(i));
  }
}
#endif  // !CASE_1
