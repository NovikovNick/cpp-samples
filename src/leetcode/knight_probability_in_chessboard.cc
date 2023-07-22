#ifndef LEETCODE_KNIGHT_PROBABILITY_IN_CHESSBOARD_H
#define LEETCODE_KNIGHT_PROBABILITY_IN_CHESSBOARD_H
#include <algorithm>
#include <format>
#include <iostream>
#include <stack>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

struct Cell {
  int row, col;
  Cell operator+(const Cell& other) const {
    return {row + other.row, col + other.col};
  }
};

class Solution {
  std::vector<Cell> dirs;
  int board_size = 0;

 public:
  Solution()
      : dirs({
            {2, 1},
            {2, -1},
            {-2, 1},
            {-2, -1},
            {1, 2},
            {1, -2},
            {-1, 2},
            {-1, -2},
        }){};

  double knightProbability(int n, int k, int row, int col) {
    if (k == 0) return 1;

    board_size = n;
    double all_possible_moves = std::pow(8, k);

    std::stack<Cell> dfs;
    dfs.push({row, col});

    uint64_t on_board_moves = 0;
    while (--k >= 0) {
      const auto cell = dfs.top();
      dfs.pop();

      for (const auto dir : dirs) {
        const auto next = cell + dir;
        if (isOnBound(next)) {
          debug(" [{}, {}] on bound\n", next.row, next.col);
          dfs.push(next);
          ++on_board_moves;
        }
      }
    }

    return on_board_moves / all_possible_moves;
  }

  bool isOnBound(const Cell& cell) const { return isOnBound(cell.row, cell.col); }

  bool isOnBound(const int row, const int col) const {
    return (row >= 0 && row < board_size) && (col >= 0 && col < board_size);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_KNIGHT_PROBABILITY_IN_CHESSBOARD_H
