#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/summary_ranges.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums { 0, 1, 2, 4, 5, 7 };
  std::vector<std::string> expected { "0->2", "4->5", "7"};

  // act
  auto res = solution.summaryRanges(nums);

  // assert
  BOOST_CHECK_EQUAL(expected.size(), res.size());
  for (int i = 0; i < expected.size(); ++i) {
    BOOST_CHECK_EQUAL(expected[i], res[i]);
  }
}
#endif  // !CASE_1
