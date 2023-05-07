#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/find_the_longest_valid_obstacle_course_at_each_position.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> obstacles{5, 1, 5, 5, 1, 3, 4, 5, 1, 4};
  std::vector<int> expected{1, 1, 2, 3, 2, 3, 4, 5, 3, 5};
  
  // act
  auto res = solution.longestObstacleCourseAtEachPosition(obstacles);

  // assert
  BOOST_CHECK_EQUAL(expected.size(), res.size());
  for (int i = 0; i < expected.size(); ++i) {
    BOOST_CHECK_EQUAL(expected[i], res[i]);
  }

}
#endif  // !CASE_1
