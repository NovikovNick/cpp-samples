#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/average_salary_excluding_the_minimum_and_maximum_salary.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> salary{4000, 3000, 1000, 2000};

  // act
  auto res = solution.average(salary);

  // assert
  BOOST_CHECK_EQUAL(2500, res);
}
#endif  // !CASE_1
