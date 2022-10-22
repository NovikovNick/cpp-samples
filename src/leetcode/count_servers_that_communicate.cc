#include <algorithm>
#include <format>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

#ifndef LEETCODE_TWO_SUM_H
#define LEETCODE_TWO_SUM_H

namespace leetcode {

using namespace std;

class Solution {
 public:
  int countServers(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    std::vector<int> rows(m, 0);
    std::vector<int> cols(n, 0);
    int total = 0;

    for (int row = 0; row < m; ++row) {
      for (int col = 0; col < n; ++col) {
        if (grid[row][col] == 1) {
          ++cols[col];
          ++rows[row];
          ++total;
        }
      }
    }

    for (int row = 0; row < m; ++row) {
      for (int col = 0; col < n; ++col) {
        if (grid[row][col] == 1 && cols[col] == 1 && rows[row] == 1) {
          --total;
        }
      }
    }

    /*std::cout << "   ";
    for (auto it : cols) {
      std::cout << std::format("{:2d} ", it);
    }
    std::cout << std::endl;
    for (int x = 0; x < m; ++x) {
      std::cout << std::format("{:2d} ", rows[x]);
      for (int y = 0; y < m; ++y) {
        std::cout << std::format("{:2d} ", grid[x][y]);
      }
      std::cout << std::endl;
    }
    std::cout << "Total =  " << total << std::endl;*/

    return total;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_TWO_SUM_H
