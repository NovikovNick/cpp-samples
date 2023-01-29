#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/lfu_cache.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::LFUCache cache(2);

  // act & assert
  cache.put(1, 1);
  cache.put(2, 2);
  debug("1 -> {}\n", cache.get(1));
  cache.put(3, 3);
  debug("2 -> {}\n", cache.get(2));
  debug("3 -> {}\n", cache.get(3));
  cache.put(4, 4);
  debug("1 -> {}\n", cache.get(1));
  debug("3 -> {}\n", cache.get(3));
  debug("4 -> {}\n", cache.get(4));
}
#endif  // !CASE_1
