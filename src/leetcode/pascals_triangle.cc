#ifndef LEETCODE_PASCALS_TRIANGLE_H
#define LEETCODE_PASCALS_TRIANGLE_H
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
  vector<vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> res;
    for (int row = 1; row <= numRows; ++row) {
      res.emplace_back(row);
      for (int col = 0; col < row; ++col) {
        if (col == 0 || col == (row - 1)) {
          res[row - 1][col] = 1;
        } else {
          res[row - 1][col] = res[row - 2][col - 1] + res[row - 2][col];
        }
      }
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_PASCALS_TRIANGLE_H
