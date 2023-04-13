#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/validate_stack_sequences.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> pushed{1, 2, 3, 4, 5};
  std::vector<int> popped{4, 5, 3, 2, 1};
  // act
  auto res = solution.validateStackSequences(pushed, popped);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
