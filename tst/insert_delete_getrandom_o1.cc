#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/insert_delete_getrandom_o1.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  auto randomizedSet = leetcode::RandomizedSet();

  // act
  randomizedSet.insert(1);  // Inserts 1 to the set. Returns true as 1 was inserted successfully.
  randomizedSet.remove(2);  // Returns false as 2 does not exist in the set.
  randomizedSet.insert(2);  // Inserts 2 to the set, returns true. Set now contains [1,2].
  randomizedSet.getRandom();// getRandom() should return either 1 or 2 randomly.
  randomizedSet.remove(1);  // Removes 1 from the set, returns true. Set now contains [2].
  randomizedSet.insert(2);  // 2 was already in the set, so return false.
  randomizedSet.getRandom();// Since 2 is the only number in the set,
                            // getRandom() will always return 2.
  // assert
  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
