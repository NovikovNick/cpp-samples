#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/best_team_with_no_conflicts.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> scores{596, 277, 897, 622, 500, 299, 34,  536, 797,
                          32,  264, 948, 645, 537, 83,  589, 770};
  std::vector<int> ages{18, 52, 60, 79, 72, 28, 81, 33, 96,
                        15, 18, 5,  17, 96, 57, 72, 72};

  // act
  auto res = solution.bestTeamScore(scores, ages);

  // assert
  BOOST_CHECK_EQUAL(3287, res);
}
#endif  // !CASE_1
