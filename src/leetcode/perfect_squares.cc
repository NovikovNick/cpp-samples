#ifndef LEETCODE_PERFECT_SQUARES_H
#define LEETCODE_PERFECT_SQUARES_H
#include <algorithm>
#include <format>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

// Bruteforce DFS solution
//
// class Solution {
// public:
//  int numSquares(int n) { return dfs(n, 0); }
//
//  int dfs(const int n, const int depth) {
//    if (n == 0) return depth;
//    int res = 10000;
//    for (int i = 1; (i * i) <= n; ++i)
//      res = std::min(res, dfs(n - i * i, depth + 1));
//    return res;
//  }
//};

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
  int numSquares(int n) {
    std::queue<int> bfs;
    bfs.push(n);

    int bfs_level = 0;
    while (!bfs.empty()) {
      int size = bfs.size();

      while (size--) {
        int num = bfs.front();
        bfs.pop();

        for (int i = 1, square = i * i; square <= num; ++i) {
          square = i * i;
          if ((num - square) == 0) {
            return bfs_level + 1;
          } else if ((num - square) > 0) {
            bfs.push(num - square);
          }
        }
      }
      ++bfs_level;
    }
    return bfs_level;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_PERFECT_SQUARES_H
