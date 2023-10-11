#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/number_of_flowers_in_full_bloom.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> flowers;
  std::vector<int> people;

  // act
  auto res = solution.fullBloomFlowers(flowers, people);

  // assert
  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
