#define BOOST_TEST_MODULE SolutionTest
#define CASE_4 1
#define CASE_3 0
#define CASE_2 0
#define CASE_1 0
#define DEBUG 1

#include "../src/leetcode/maximum_profit_in_job_scheduling.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> startTime{1, 2, 3, 3};
  std::vector<int> endTime{3, 4, 5, 6};
  std::vector<int> profit{50, 10, 40, 70};
  // act
  auto res = solution.jobScheduling(startTime, endTime, profit);

  // assert
  BOOST_CHECK_EQUAL(120, res);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> startTime{1, 2, 3, 4, 6};
  std::vector<int> endTime{3, 5, 10, 6, 9};
  std::vector<int> profit{20, 20, 100, 70, 60};
  // act
  auto res = solution.jobScheduling(startTime, endTime, profit);

  // assert
  BOOST_CHECK_EQUAL(150, res);
}
#endif  // !CASE_2


#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> startTime{1, 1, 1};
  std::vector<int> endTime{2, 3, 4};
  std::vector<int> profit{5, 6, 4};
  // act
  auto res = solution.jobScheduling(startTime, endTime, profit);

  // assert
  BOOST_CHECK_EQUAL(6, res);
}
#endif  // !CASE_3

#if CASE_4
BOOST_AUTO_TEST_CASE(case4) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> startTime{4, 2, 4, 8, 2};
  std::vector<int> endTime{5, 5, 5, 10, 8};
  std::vector<int> profit{1, 2, 8, 10, 4};
  // act
  auto res = solution.jobScheduling(startTime, endTime, profit);

  // assert
  BOOST_CHECK_EQUAL(18, res);
}
#endif  // !CASE_4