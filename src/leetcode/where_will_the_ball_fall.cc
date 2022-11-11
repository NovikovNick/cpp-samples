#ifndef LEETCODE_WHERE_WILL_THE_BALL_FALL_H
#define LEETCODE_WHERE_WILL_THE_BALL_FALL_H
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
  vector<int> findBall(vector<vector<int>>& grid) {
    int n = grid[0].size();
    std::vector<int> res(n, -1);
    for (int i = 0; i < n; ++i) res[i] = isReachEnd(i, grid);
    return res;
  }

  int isReachEnd(int index, vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int y = 0;
    int x = index;
    while (y < m) {
      auto el = grid[y][x];
      if (el > 0) {
        if ((x + 1) == n || (el + grid[y][x + 1]) == 0) return -1;
        ++x;
      }
      if (el < 0) {
        if ((x - 1) < 0 || (el + grid[y][x - 1]) == 0) return -1;
        --x;
      }
      ++y;
    }
    return x;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_WHERE_WILL_THE_BALL_FALL_H
