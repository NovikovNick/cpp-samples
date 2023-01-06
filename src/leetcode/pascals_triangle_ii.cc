#ifndef LEETCODE_PASCALS_TRIANGLE_II_H
#define LEETCODE_PASCALS_TRIANGLE_II_H
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
  vector<int> getRow(int row) {
    std::vector<std::vector<int>> res(2, std::vector<int>(row + 1));
    bool flag = false;
    for (int i = 0; i <= row; ++i) {
      for (int j = 0; j <= row; ++j) {
        if (j == 0 || j == row) {
          res[flag][j] = 1;
        } else {
          res[flag][j] = res[!flag][j] + res[!flag][j - 1];
        }
      }
      flag = !flag;
    }
    return res[!flag];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_PASCALS_TRIANGLE_II_H
