#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/minimum_initial_energy_to_finish_tasks.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> tasks = {{1, 2}, {2, 4}, {4, 8}};

  // act
  auto res = solution.minimumEffort(tasks);
  std::cout << " ---- " << std::endl;

  // assert
  BOOST_CHECK_EQUAL(8, res);
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> tasks = {
      {1, 3}, {2, 4}, {10, 11}, {10, 12}, {8, 9}};

  // act
  auto res = solution.minimumEffort(tasks);
  std::cout << " ---- " << std::endl;

  // assert
  BOOST_CHECK_EQUAL(32, res);
}

BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> tasks = {{1, 7},  {2, 8},  {3, 9},
                                         {4, 10}, {5, 11}, {6, 12}};

  // act
  auto res = solution.minimumEffort(tasks);
  std::cout << " ---- " << std::endl;

  // assert
  BOOST_CHECK_EQUAL(27, res);
}