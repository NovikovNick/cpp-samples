#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/cheapest_flights_within_k_stops.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std ::vector<int>> flights{{0, 1, 5}, {1, 2, 5}, {0, 3, 2},
                                         {3, 1, 2}, {1, 4, 1}, {4, 2, 1}};
  int n = 5;
  int src = 0;
  int dst = 2;
  int k = 2;
  // act
  auto res = solution.findCheapestPrice(n, flights, src, dst, k);

  // assert
  BOOST_CHECK_EQUAL(7, res);
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std ::vector<int>> flights{
      {0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
  int n = 4;
  int src = 0;
  int dst = 3;
  int k = 1;
  // act
  auto res = solution.findCheapestPrice(n, flights, src, dst, k);

  // assert
  BOOST_CHECK_EQUAL(700, res);
}
#endif  // !CASE_2
