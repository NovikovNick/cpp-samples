#ifndef LEETCODE_EXCEL_SHEET_COLUMN_TITLE_H
#define LEETCODE_EXCEL_SHEET_COLUMN_TITLE_H
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
  string convertToTitle(int col) {
    std::string res;
    int base = 26;
    int num;
    while (col != 0) {
      debug("{} % {} = {}, {} / {} = {}\n",
            col,
            base,
            col % base,
            col,
            base,
            col / base);

      if (col % base == 0) {
        num = base;
        col = col / base - 1;
      } else {
        num = col % base;
        col = col / base;
      }

      res += 'A' + num - 1;
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_EXCEL_SHEET_COLUMN_TITLE_H
