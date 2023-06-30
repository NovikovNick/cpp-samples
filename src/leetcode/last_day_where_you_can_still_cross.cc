#ifndef LEETCODE_LAST_DAY_WHERE_YOU_CAN_STILL_CROSS_H
#define LEETCODE_LAST_DAY_WHERE_YOU_CAN_STILL_CROSS_H
#include <algorithm>
#include <format>
#include <iostream>
#include <queue>
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
  std::vector<std::vector<int>> matrix;
  //std::vector<std::vector<bool>> visited;
  int rows, cols;

 public:
  int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    rows = row;
    cols = col;
    matrix = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
    //visited = std::vector<std::vector<bool>>(rows, std::vector<bool>(cols, false));

    int n = cells.size();
    for (int i = 0; i < n; ++i) {
      matrix[cells[i][0] - 1][cells[i][1] - 1] = 1;
      if (!isCrossNotExist()) return i + 1;
    }
    return n;
  }

  bool isCrossNotExist() {

    return false;
  }


};
}  // namespace leetcode
#endif  // LEETCODE_LAST_DAY_WHERE_YOU_CAN_STILL_CROSS_H
