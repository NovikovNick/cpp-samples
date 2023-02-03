#ifndef LEETCODE_ZIGZAG_CONVERSION_H
#define LEETCODE_ZIGZAG_CONVERSION_H
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
  string convert(string s, int numRows) {
    if (numRows == 1) return s;

    int n = s.size();
    std::vector<std::string> rows(numRows);

    bool forward = true;
    int row = 0;
    for (int i = 0; i < n; ++i, row = forward ? row + 1 : row - 1) {
      rows[row] += s[i];

      if (forward) {
        if (row + 1 == numRows) forward = false;
      } else {
        if (row - 1 < 0) forward = true;
      }
    }

    std::string res;
    for (const auto& str : rows) res.append(str);
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_ZIGZAG_CONVERSION_H
