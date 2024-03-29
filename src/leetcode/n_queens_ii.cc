#ifndef LEETCODE_N_QUEENS_II_H
#define LEETCODE_N_QUEENS_II_H
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
  using BOARD = std::vector<std::vector<bool>>;

 public:
  int totalNQueens(int n) {
    BOARD board(n, std::vector<bool>(n));
    int res = 0;
    res += backtracking(0, 0, board);
    return res;
  }

  int backtracking(const int i, const int queen_count, BOARD& board) {
    int n = board.size();
    if (queen_count == n) return 1;
    int count = 0;
    for (int j = i; j < n * n; ++j) {
      int row = j / n;
      int col = j % n;
      if (notOnAttack(row, col, board)) {
        placeQueen(row, col, board);
        //debug("{}. place queen at {} {} {}\n", queen_count, j, row, col);
        //print(board);
        count += backtracking(j + 1, queen_count + 1, board);
        removeQueen(row, col, board);
        //debug("{}. remove queen from {} {} {}\n", queen_count, j, row, col);
      }
    }
    return count;
  }

  void print(BOARD& board) {
    int n = board.size();
    for (int j = 0; j < n * n; ++j) {
      int row = j / n;
      int col = j % n;
      debug("{} ", notOnAttack(row, col, board) ? "*" : "0");
      if (col == (n - 1)) debug("\n");
    }
    debug("\n");
  }

  void placeQueen(const int x, const int y, BOARD& board) {
    board[x][y] = true;
  }
  void removeQueen(const int x, const int y, BOARD& board) {
    board[x][y] = false;
  }

  bool notOnAttack(const int x, const int y, BOARD& board) {
    int n = board.size();
    for (int row = 0; row < n; ++row)
      if (board[row][y]) return false;
    for (int col = 0; col < n; ++col)
      if (board[x][col]) return false;

    for (int row = x, col = y; row < n && col < n; ++col, ++row)
      if (board[row][col]) return false;
    for (int row = x, col = y; row < n && col >= 0; --col, ++row)
      if (board[row][col]) return false;
    for (int row = x, col = y; row >= 0 && col >= 0; --col, --row)
      if (board[row][col]) return false;
    for (int row = x, col = y; row >= 0 && col < n; ++col, --row)
      if (board[row][col]) return false;

    return true;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_N_QUEENS_II_H
