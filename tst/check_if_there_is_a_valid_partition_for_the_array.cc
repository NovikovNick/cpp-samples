#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/check_if_there_is_a_valid_partition_for_the_array.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{4, 4, 4, 5, 6};

  // act
  auto res = solution.validPartition(nums);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
