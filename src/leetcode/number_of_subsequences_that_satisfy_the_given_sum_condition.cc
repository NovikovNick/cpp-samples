#ifndef LEETCODE_NUMBER_OF_SUBSEQUENCES_THAT_SATISFY_THE_GIVEN_SUM_CONDITION_H
#define LEETCODE_NUMBER_OF_SUBSEQUENCES_THAT_SATISFY_THE_GIVEN_SUM_CONDITION_H
#include <algorithm>
#include <format>
#include <iostream>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

class Solution {
 public:
  int numSubseq(vector<int>& nums, int target) {
    debug("Need to find number of subsequence\n");
    return 1;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_NUMBER_OF_SUBSEQUENCES_THAT_SATISFY_THE_GIVEN_SUM_CONDITION_H
