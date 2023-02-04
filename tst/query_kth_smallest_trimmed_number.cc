#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/query_kth_smallest_trimmed_number.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> nums{"102", "473", "251", "814"};
  std::vector<std::vector<int>> queries{{1, 1}, {2, 3}, {4, 2}, {1, 2}};
  
  // act
  auto res = solution.smallestTrimmedNumbers(nums, queries);

  // assert
  for (const auto& num : res) debug("{} ", num);
  debug("\n");
}
#endif  // !CASE_1
