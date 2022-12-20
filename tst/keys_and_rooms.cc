#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/keys_and_rooms.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> rooms{{1, 2}, {2, 1}, {1}};

  // act
  auto res = solution.canVisitAllRooms(rooms);

  // assert
  BOOST_CHECK(!res);
}
#endif  // !CASE_1
