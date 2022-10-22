#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/count_servers_that_communicate.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> grid = {{1, 0}, {0, 1}};

  // act
  auto res = solution.countServers(grid);

  // assert
  BOOST_CHECK_EQUAL(0, res);
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> grid = {{1, 0}, {1, 1}};

  // act
  auto res = solution.countServers(grid);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}

BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> grid = {
      {1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

  // act
  auto res = solution.countServers(grid);

  // assert
  BOOST_CHECK_EQUAL(4, res);
}
