#ifndef LEETCODE_REMOVE_ALL_ADJACENT_DUPLICATES_IN_STRING_H
#define LEETCODE_REMOVE_ALL_ADJACENT_DUPLICATES_IN_STRING_H
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
  string removeDuplicates(string s) {
    std::string res = {s[0]};
    for (int i = 1; i < s.size(); ++i) {
      if (!res.empty() && res.back() == s[i]) {
        res.pop_back();
      } else {
        res.push_back(s[i]);
      }
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_REMOVE_ALL_ADJACENT_DUPLICATES_IN_STRING_H
