#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/design_underground_system.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::UndergroundSystem solution;

  // act
  solution.checkIn(45, "Leyton", 3);
  solution.checkIn(32, "Paradise", 8);
  solution.checkIn(27, "Leyton", 10);
  solution.checkOut(45, "Waterloo", 15);
  solution.checkOut(27, "Waterloo", 20);
  solution.checkOut(32, "Cambridge", 22);
  BOOST_CHECK_EQUAL(14, solution.getAverageTime("Paradise", "Cambridge"));

  // auto res = solution.test(1);

  // assert
}
#endif  // !CASE_1
