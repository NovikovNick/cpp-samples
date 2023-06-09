#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/find_smallest_letter_greater_than_target.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<char> letters{'c', 'f', 'j'};
  // act
  auto res = solution.nextGreatestLetter(letters, 'c');

  // assert
  BOOST_CHECK_EQUAL('f', res);
}
#endif  // !CASE_1
