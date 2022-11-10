#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define CASE_2 1
#define DEBUG 1

#include "../src/leetcode/remove_all_adjacent_duplicates_in_string.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.removeDuplicates("abbaca");

  // assert
  BOOST_CHECK_EQUAL("ca", res);
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.removeDuplicates("azxxzy");

  // assert
  BOOST_CHECK_EQUAL("ay", res);
}
#endif  // !CASE_2
