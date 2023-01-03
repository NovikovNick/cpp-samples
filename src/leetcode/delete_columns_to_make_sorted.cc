#ifndef LEETCODE_DELETE_COLUMNS_TO_MAKE_SORTED_H
#define LEETCODE_DELETE_COLUMNS_TO_MAKE_SORTED_H
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
  int minDeletionSize(std::vector<std::string> strs) {
    int n = strs[0].size(), m = strs.size();
    if (m < 2) return 0;

    int res = 0;
    for (int col = 0; col < n; ++col) {
      for (int row = 1; row < m; ++row) {
        if (strs[row][col] < strs[row - 1][col]) {
          ++res;
          break;
        }
      }
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_DELETE_COLUMNS_TO_MAKE_SORTED_H
