#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/group_the_people_given_the_group_size_they_belong_to.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> groupSizes{3, 3, 3, 3, 3, 1, 3};

  // act
  auto res = solution.groupThePeople(groupSizes);

  // assert
  for (const auto group : res) {
    debug("group: ");
    std::copy(group.begin(),  //
              group.end(),    //
              std::ostream_iterator<int>(std::cout, " "));
    debug("\n");
  }
}
#endif  // !CASE_1
