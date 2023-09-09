#ifndef LEETCODE_COMBINATION_SUM_IV_H
#define LEETCODE_COMBINATION_SUM_IV_H
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
  int combinationSum4(vector<int>& nums, int target) {

    std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, ", "));
    debug("\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_COMBINATION_SUM_IV_H
