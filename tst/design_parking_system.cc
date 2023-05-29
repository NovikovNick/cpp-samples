#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/design_parking_system.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::ParkingSystem solution{1,1,0};

  // act & assert
  BOOST_CHECK(solution.addCar(1));
  BOOST_CHECK(solution.addCar(2));
  BOOST_CHECK(!solution.addCar(3));
  BOOST_CHECK(!solution.addCar(1));
}
#endif  // !CASE_1
