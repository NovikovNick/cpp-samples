#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/non_overlapping_intervals.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> intervals{{-52, 31},
                                          {-73, -26},
                                          {82, 97},
                                          {-65, -11},
                                          {-62, -49},
                                          {95, 99},
                                          {58, 95},
                                          {-31, 49},
                                          {66, 98},
                                          {-63, 2},
                                          {30, 47},
                                          {-40, -26}};
  
  // act
  auto res = solution.eraseOverlapIntervals(intervals);

  // assert
  BOOST_CHECK_EQUAL(7, res);
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> intervals{{1, 2}, {2, 3}, {3, 4}, {1, 3}};

  // act
  auto res = solution.eraseOverlapIntervals(intervals);

  // assert
  BOOST_CHECK_EQUAL(1, res);
}
#endif  // !CASE_2