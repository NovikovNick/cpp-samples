#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#include "../src/leetcode/can_make_arithmetic_progression_from_sequence.cc"

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> arr{3, 1, 5};

  // act
  auto res = solution.canMakeArithmeticProgression(arr);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
