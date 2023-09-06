#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/split_linked_list_in_parts.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.splitListToParts(nullptr, 5);

  // assert
  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
