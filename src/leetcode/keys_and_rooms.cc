#ifndef LEETCODE_KEYS_AND_ROOMS_H
#define LEETCODE_KEYS_AND_ROOMS_H
#include <algorithm>
#include <format>
#include <iostream>
#include <queue>
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
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    std::vector<bool> visited(n, false);
    std::stack<int> dfs;
    dfs.push(0);
    visited[0] = true;
    int count = 0;
    while (!dfs.empty()) {
      auto key = dfs.top();
      dfs.pop();
      ++count;
      for (const auto& akey : rooms[key])
        if (!visited[akey]) {
          dfs.push(akey);
          visited[akey] = true;
        }
    }
    return n == count;
  }

  /*bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    std::vector<bool> visited(n, false);
    std::queue<int> bfs;
    bfs.push(0);
    visited[0] = true;

    int count = 0;
    while (!bfs.empty()) {
      auto key = bfs.front();
      bfs.pop();
      ++count;
      for (const auto& akey : rooms[key])
        if (!visited[akey]) {
          bfs.push(akey);
          visited[akey] = true;
        }
    }
    return n == count;
  }*/
};
}  // namespace leetcode
#endif  // LEETCODE_KEYS_AND_ROOMS_H
