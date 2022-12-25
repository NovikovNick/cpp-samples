#define BOOST_TEST_MODULE SolutionTest
#define CASE_2 1
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/longest_subsequence_with_limited_sum.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{469781, 45635, 628818, 324948, 343772, 713803, 452081};
  std::vector<int> queries{816646, 929491};
  std::vector<int> expected{3, 3};

  // act
  auto res = solution.answerQueries(nums, queries);

  // assert
  for (int i = 0; i < expected.size(); ++i)
    BOOST_CHECK_EQUAL(res[i], expected[i]);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{4, 5, 2, 1};
  std::vector<int> queries{3, 10, 21};
  std::vector<int> expected{2, 3, 4};

  // act
  auto res = solution.answerQueries(nums, queries);

  // assert
  for (int i = 0; i < expected.size(); ++i)
    BOOST_CHECK_EQUAL(res[i], expected[i]);
}
#endif  // !CASE_2