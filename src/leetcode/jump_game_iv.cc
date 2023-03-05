#ifndef LEETCODE_JUMP_GAME_IV_H
#define LEETCODE_JUMP_GAME_IV_H
#include <algorithm>
#include <format>
#include <iostream>
#include <queue>
#include <unordered_map>
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
  int minJumps(vector<int>& arr) {
    int n = arr.size();

    std::unordered_map<int, std::vector<int>> router;
    for (int i = 0; i < n; ++i) router[arr[i]].push_back(i);
    
    int start = 0; 
    int finish = n - 1;

    std::vector<int> dp(n, n - 1);
    std::queue<int> bfs;
    bfs.push(start);
    int jumps = 0;
    dp[start] = jumps;
    while (!bfs.empty()) {
      int size = bfs.size();
      while (--size >= 0) {
        auto i = bfs.front();
        bfs.pop();
        if (i == finish) return jumps;


        if (i - 1 >= 0 && dp[i - 1] > jumps + 1) {
          dp[i - 1] = jumps + 1;
          bfs.push(i - 1);
        }
        if (i + 1 < n && dp[i + 1] > jumps + 1) {
          dp[i + 1] = jumps + 1;
          bfs.push(i + 1);
        }

        for (const auto j : router[arr[i]]) {
          if (i != j && dp[j] > jumps + 1) {
            dp[j] = jumps + 1;
            bfs.push(j);
          }
        }

        router[arr[i]].clear();
      }
      ++jumps;
    }
    return jumps;
  }
};
}  // namespace leetcode
#endif  // LEETCODE__H
