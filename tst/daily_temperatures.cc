#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/daily_temperatures.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
  std::vector<int> expected{1, 1, 4, 2, 1, 1, 0, 0};

  // act
  auto res = solution.dailyTemperatures(temperatures);

  // assert
  for (auto i = 0; auto it : expected) {
    BOOST_CHECK_EQUAL(it, res[i++]);
  }
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> temperatures{30, 40, 50, 60};
  std::vector<int> expected{1, 1, 1, 0};

  // act
  auto res = solution.dailyTemperatures(temperatures);

  // assert
  for (auto i = 0; auto it : expected) {
    BOOST_CHECK_EQUAL(it, res[i++]);
  }
}

BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> temperatures{30, 60, 90};
  std::vector<int> expected{1, 1, 0};

  // act
  auto res = solution.dailyTemperatures(temperatures);

  // assert
  for (auto i = 0; auto it : expected) {
    BOOST_CHECK_EQUAL(it, res[i++]);
  }
}
