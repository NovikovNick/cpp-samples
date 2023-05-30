#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/design_hashset.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::MyHashSet solution;

  // act & assert
  solution.add(1);
  solution.add(2);

  BOOST_CHECK(!solution.contains(3));
  BOOST_CHECK(solution.contains(1));
  BOOST_CHECK(solution.contains(2));
  solution.remove(2);
  BOOST_CHECK(!solution.contains(2));
}
#endif  // !CASE_1
