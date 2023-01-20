#ifndef LEETCODE_NON_DECREASING_SUBSEQUENCES_H
#define LEETCODE_NON_DECREASING_SUBSEQUENCES_H
#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_set>
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
  vector<vector<int>> findSubsequences(vector<int>& nums) { return {}; }
};
}  // namespace leetcode
#endif  // LEETCODE__H
