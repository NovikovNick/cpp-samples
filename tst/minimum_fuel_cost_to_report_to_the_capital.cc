#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define CASE_2 2
#define DEBUG 1

#include "../src/leetcode/minimum_fuel_cost_to_report_to_the_capital.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> minimumFuelCost{{3, 1}, {3, 2}, {1, 0},
                                                {0, 4}, {0, 5}, {4, 6}};
   // act
  auto res = solution.minimumFuelCost(minimumFuelCost, 2);

  // assert
  BOOST_CHECK_EQUAL(7, res);
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> minimumFuelCost{
      {3, 1}, {3, 2}, {1, 0}, {0, 4}, {0, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}};
  // act
  auto res = solution.minimumFuelCost(minimumFuelCost, 2);

  // assert
  BOOST_CHECK_EQUAL(14, res);
}
#endif  // !CASE_2
