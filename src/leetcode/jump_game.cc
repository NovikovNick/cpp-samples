#ifndef LEETCODE_JUMP_GAME_H
#define LEETCODE_JUMP_GAME_H
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
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  } 

  bool canJump(vector<int>& nums) { return dfs(0, nums); }

  bool dfs(const int i, std::vector<int>& nums) {
    if (i + nums[i] >= nums.size() - 1) return true;
    int steps = i + nums[i];
    nums[i] = 0;
    for (int j = steps; j > i; --j)
      if (nums[j] > 0 && dfs(j, nums)) return true;
    return false;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_JUMP_GAME_H
