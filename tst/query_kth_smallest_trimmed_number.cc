#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define CASE_2 1
#define CASE_3 1
#define DEBUG 1

#include "../src/leetcode/query_kth_smallest_trimmed_number.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> nums{
      "8331019423839036903", "2215783497319194533", "3244863164120264914",
      "2723857887888553250", "1069645833408356268", "3799170975306313470",
      "3300849027471666477", "8896469467436127218", "9595084104356246555",
      "4601424390471226348", "2777623221871959897", "2660664761264162910",
      "4830224756337097853", "2239177595019260973", "5704104074606481922",
      "5158962343348888307", "4957489822885409209", "5533958195540658313",
      "6712811206814843536", "9775503283462317096", "1975389311819120035",
      "1292135637676764140", "9838972337538013522", "7609294617007602893",
      "0186572359592634437", "9236053726818307461", "7264888050655615544",
      "4990296885039745852", "1417868535147288083"};
  std::vector<std::vector<int>> queries{
      {22, 19}, {16, 17}, {10, 7},  {27, 16}, {9, 9},  {21, 4},
      {24, 2},  {12, 11}, {2, 5},   {24, 12}, {25, 7}, {7, 13},
      {14, 9},  {23, 15}, {18, 17}, {22, 16}, {4, 14}, {14, 17},
      {25, 11}, {12, 16}, {29, 3},  {22, 11}, {29, 2}, {24, 2},
      {24, 15}, {7, 14},  {7, 3},   {7, 14},  {1, 3}};

  // act
  auto res = solution.smallestTrimmedNumbers(nums, queries);

  // assert
  std::vector<int> expected{26, 16, 16, 13, 12, 19, 13, 22, 25, 11,
                            0,  10, 19, 3,  11, 10, 0,  13, 3,  2,
                            13, 5,  10, 13, 2,  12, 3,  12, 20};
  for (int i = 0; i < expected.size(); i++) {
    BOOST_CHECK_EQUAL(expected[i], res[i]);
    debug("{} ", res[i]);
  }
  debug("\n");
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> nums{"102", "473", "251", "814"};
  std::vector<std::vector<int>> queries{{1, 1}, {2, 3}, {4, 2}, {1, 2}};

  // act
  auto res = solution.smallestTrimmedNumbers(nums, queries);

  // assert
  for (const auto& num : res) debug("{} ", num);
  debug("\n");
}
#endif  // !CASE_2

#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> nums{"24", "37", "96", "04"};
  std::vector<std::vector<int>> queries{{2, 1}, {2, 2}};

  // act
  auto res = solution.smallestTrimmedNumbers(nums, queries);

  // assert
  std::vector<int> expected{3, 0};
  for (int i = 0; i < expected.size(); i++) {
    BOOST_CHECK_EQUAL(expected[i], res[i]);
    debug("{} ", res[i]);
  }
  debug("\n");
}
#endif  // !CASE_3