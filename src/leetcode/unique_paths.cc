#ifndef LEETCODE_UNIQUE_PATHS_H
#define LEETCODE_UNIQUE_PATHS_H
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

template <int ROWS, int COLS>
class DP final {
  using size_t = uint64_t;
  size_t size_ = (ROWS + 1) * (COLS + 1);
  size_t dp_[(ROWS + 1) * (COLS + 1)];

 public:
  constexpr DP() {
    for (uint64_t i = 0; i < size_; ++i) dp_[i] = 1;

    for (size_t row = 2; row <= ROWS; ++row) {
      for (size_t col = 2; col <= COLS; ++col) {
        elem(row, col) = elem(row - 1, col) + elem(row, col - 1);
      }
    }
  }

  int operator()(const int row, const int col) const {
    return static_cast<int>(dp_[row * COLS + col]);
  };

 private:
  constexpr size_t& elem(const size_t row, const size_t col) {
    return dp_[row * COLS + col];
  };
};

constexpr DP<100, 100> dp;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    return dp(m, n);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_UNIQUE_PATHS_H
