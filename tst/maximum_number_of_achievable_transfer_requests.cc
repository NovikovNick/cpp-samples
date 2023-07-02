#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/maximum_number_of_achievable_transfer_requests.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 5;
  std::vector<std::vector<int>> requests{
      {0, 1}, {1, 0}, {0, 1}, {1, 2}, {2, 0}, {3, 4}};

  // act
  auto res = solution.maximumRequests(n, requests);

  // assert
  BOOST_CHECK_EQUAL(5, res);
}
#endif  // !CASE_1
