#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/snapshot_array.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::SnapshotArray solution(2);

  // act & assert
  BOOST_CHECK_EQUAL(0, solution.snap());
  BOOST_CHECK_EQUAL(0, solution.get(1, 0));
  BOOST_CHECK_EQUAL(0, solution.get(0, 0));
  solution.set(1, 8);
  BOOST_CHECK_EQUAL(0, solution.get(1, 0));
  solution.set(0, 20);
  BOOST_CHECK_EQUAL(0, solution.get(0, 0));
  solution.set(0, 7);
}
#endif  // !CASE_1
