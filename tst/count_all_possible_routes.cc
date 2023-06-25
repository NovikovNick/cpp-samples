#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/count_all_possible_routes.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> location { 2, 3, 6, 8, 4 };
  const int start = 1;
  const int finish = 3;
  const int fuel = 5;

  // act
  auto res = solution.countRoutes(location, start, finish, fuel);

  // assert
  BOOST_CHECK_EQUAL(4, res);
}
#endif  // !CASE_1
