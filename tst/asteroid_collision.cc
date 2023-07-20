#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/asteroid_collision.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> asteroids{10, 2, -5};
  std::vector<int> expected{10};

  // act
  auto res = solution.asteroidCollision(asteroids);

  // assert
  if (expected.size() == res.size()) {
    for (int i = 0; i < expected.size(); ++i) BOOST_CHECK_EQUAL(expected[i], res[i]);
  } else {
    for (const auto it : res) debug("{} ", it);
    debug("\n");
    BOOST_CHECK(false);
  }
}
#endif  // !CASE_1
