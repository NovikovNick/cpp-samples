#ifndef LEETCODE_MINIMUM_TIME_TO_COLLECT_ALL_APPLES_IN_A_TREE_H
#define LEETCODE_MINIMUM_TIME_TO_COLLECT_ALL_APPLES_IN_A_TREE_H
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
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    std::vector<std::vector<int>> nodes(n);
    for (const auto& edge : edges) {
      nodes[edge[0]].push_back(edge[1]);
      nodes[edge[1]].push_back(edge[0]);
    }

    int steps = -1;
    checkAppleDFS(-1, 0, steps, nodes, hasApple);
    return steps;
  }

  bool checkAppleDFS(const int parent_index, const int index, int& steps,
                     vector<vector<int>>& nodes, vector<bool>& hasApple) {
    ++steps;
    bool childred_have_apple = false;
    for (const auto& child_index : nodes[index]) {
      if (parent_index == child_index) continue;

      bool child_has_apple =
          checkAppleDFS(index, child_index, steps, nodes, hasApple);
      if (child_has_apple) {
        ++steps;
      } else {
        --steps;
      }
      childred_have_apple = childred_have_apple || child_has_apple;
    }
    return hasApple[index] || childred_have_apple;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_TIME_TO_COLLECT_ALL_APPLES_IN_A_TREE_H
