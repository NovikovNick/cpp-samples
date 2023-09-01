#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/counting_bits.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> expected{0, 1, 1, 2, 1, 2};

  // act
  auto res = solution.countBits(5);

  // assert
  for (int i = 0; i < res.size(); ++i) {
    debug("{}\n", res[i]);
    BOOST_CHECK_EQUAL(expected[i], res[i]);
  }
}
#endif  // !CASE_1
