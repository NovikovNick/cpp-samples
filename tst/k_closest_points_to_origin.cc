#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/k_closest_points_to_origin.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> points{{1, 1}, {2, 2}, {3, 3}};
  int k = 2;

  // act
  auto res = solution.kClosest(points, k);

  // assert
  for (const auto& point : res) {
    debug("[{},{}]\n", point[0], point[1]);
  }
}
#endif  // !CASE_1
