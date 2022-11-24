#ifndef LEETCODE_WORD_SEARCH_H
#define LEETCODE_WORD_SEARCH_H
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

using Board = std::vector<std::vector<char>>;
class Solution {
  std::vector<std::pair<int, int>> dirs_;

 public:
  Solution() : dirs_({{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  bool exist(Board& board, std::string word) {
    int m = board.size(), n = board[0].size();
    for (uint8_t row = 0; row < m; ++row)
      for (uint8_t col = 0; col < n; ++col)
        if (board[row][col] == word[0] && dfs(row, col, word, 0, board))
          return true;
    return false;
  }

  bool dfs(const uint8_t row, const uint8_t col, std::string& word,
           const uint8_t word_index, Board& board) {
    auto ch = board[row][col];
    if (word_index == (word.size() - 1)) return true;
    board[row][col] = '#';
    const uint8_t m = board.size(), n = board[0].size();
    for (const auto [dx, dy] : dirs_) {
      const uint8_t nxt_row = row + dx;
      const uint8_t nxt_col = col + dy;
      if (nxt_row < 0 || nxt_row >= m) continue;
      if (nxt_col < 0 || nxt_col >= n) continue;
      auto nxt_ch = board[nxt_row][nxt_col];
      if (nxt_ch != '#' && nxt_ch == word[word_index + 1])
        if (dfs(nxt_row, nxt_col, word, word_index + 1, board)) return true;
    }
    board[row][col] = ch;
    return false;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_WORD_SEARCH_H
