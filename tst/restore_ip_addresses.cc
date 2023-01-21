#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/restore_ip_addresses.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.restoreIpAddresses("25525511135");

  // assert
  debug("----------------\n");
  for (const auto& it : res) debug("{}\n", it);
}
#endif  // !CASE_1
