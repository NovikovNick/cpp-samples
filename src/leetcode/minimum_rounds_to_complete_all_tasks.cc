#ifndef LEETCODE_MINIMUM_ROUNDS_TO_COMPLETE_ALL_TASKS_H
#define LEETCODE_MINIMUM_ROUNDS_TO_COMPLETE_ALL_TASKS_H
#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_map>
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
  int minimumRounds(vector<int>& tasks) {
    std::unordered_map<int, int> freq;
    for (const auto& task : tasks) ++freq[task];

    int res = 0;
    for (const auto& [key, val] : freq) {
      if (val <= 1) return -1;
      res += minimumRounds(val);
    }
    return res;
  }

  inline int minimumRounds(const int freq) { return (freq - 1) / 3 + 1; }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_ROUNDS_TO_COMPLETE_ALL_TASKS_H
