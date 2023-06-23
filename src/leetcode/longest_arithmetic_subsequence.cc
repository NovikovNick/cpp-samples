#ifndef LEETCODE_LONGEST_ARITHMETIC_SUBSEQUENCE_H
#define LEETCODE_LONGEST_ARITHMETIC_SUBSEQUENCE_H
#include <algorithm>
#include <format>
#include <iostream>
#include <vector>
#include <stack>

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
  int longestArithSeqLength(vector<int>& nums) {
    std::stack<int> stack;

    for (const auto num : nums) {
      debug("{} ", num);
    }
    debug("\n");
    return stack.size();
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LONGEST_ARITHMETIC_SUBSEQUENCE_H
