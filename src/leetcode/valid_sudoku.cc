#ifndef LEETCODE_VALID_SUDOKU_H
#define LEETCODE_VALID_SUDOKU_H
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
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  bool isValidSudoku(vector<vector<char>>& board) {
    std::unordered_set<uint8_t> row_set, col_set, box_set;

    for (uint8_t index = 0, row = 0; row < 3; ++row) {
      for (uint8_t col = 0; col < 3; ++col) {
        row_set.clear();
        col_set.clear();
        box_set.clear();

        for (uint8_t i = 0; i < 9; ++i) {
          if (isNotUnique(parse(board[index][i]), row_set)) return false;
          if (isNotUnique(parse(board[i][index]), col_set)) return false;
        }

        for (uint8_t box_row = 0; box_row < 3; ++box_row)
          for (uint8_t box_col = 0; box_col < 3; ++box_col)
            if (isNotUnique(parse(board[box_row + (row * 3)][box_col + (col * 3)]), box_set)) 
                return false;

        ++index;
      }
    }
    return true;
  }

  uint8_t parse(const char ch) { return ch == '.' ? 0 : (ch - '0'); }

  bool isNotUnique(const uint8_t num, std::unordered_set<uint8_t>& set) {
    if (num == 0) return false;
    return !set.insert(num).second;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_VALID_SUDOKU_H
