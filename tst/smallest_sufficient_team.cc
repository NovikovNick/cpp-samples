#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/smallest_sufficient_team.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> req_skills{"java", "nodejs", "reactjs"};
  std::vector<std::vector<std::string>> people{
      {"java"}, {"nodejs"}, {"nodejs", "reactjs"}};
  std::vector<int> expected{0, 2};

  // act
  auto res = solution.smallestSufficientTeam(req_skills, people);

  // assert
  if (res.size() == expected.size()) {
    for (int i = 0; i < expected.size(); ++i) {
      BOOST_CHECK_EQUAL(expected[i], res[i]);
    }
  } else {
    BOOST_CHECK(false);
  }
}
#endif  // !CASE_1
