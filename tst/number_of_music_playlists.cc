#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/number_of_music_playlists.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 3;
  int goal = 3;
  int k = 1;

  // act
  auto res = solution.numMusicPlaylists(n, goal, k);

  // assert
  BOOST_CHECK_EQUAL(6, res);
}
#endif  // !CASE_1
