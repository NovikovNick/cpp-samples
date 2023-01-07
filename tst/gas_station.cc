#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/gas_station.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> gas{1, 2, 3, 4, 5, 5, 70};
  std::vector<int> cost{2, 3, 4, 3, 9, 6, 2};

  // act
  auto res = solution.canCompleteCircuit(gas, cost);

  // assert
  BOOST_CHECK_EQUAL(6, res);
}
#endif  // !CASE_1
