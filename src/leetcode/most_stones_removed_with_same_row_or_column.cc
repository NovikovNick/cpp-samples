#ifndef LEETCODE_MOST_STONES_REMOVED_WITH_SAME_ROW_OR_COLUMN_H
#define LEETCODE_MOST_STONES_REMOVED_WITH_SAME_ROW_OR_COLUMN_H
#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
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
  int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    std::vector<int> parents(n);
    for (int i = 0; auto& it : parents) it = i++;

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (IsConected(i, j, stones)) {
          Union(GetParent(i, parents), j, parents);
        }
      }
    }

    std::unordered_set<int> unique_groups(parents.begin(), parents.end());
    return n - unique_groups.size();
  }

  bool IsConected(const int& i, const int& j,
                  std::vector<vector<int>>& stones) {
    return stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1];
  }

  int GetParent(const int& i, std::vector<int>& parents) {
    return i == parents[i] ? i : GetParent(parents[i], parents);
  }

  void Union(const int& group, const int& i, std::vector<int>& parents) {
    int parent = GetParent(i, parents);
    if (i == GetParent(i, parents)) {
      parents[i] = group;
    } else {
      for (auto& it : parents)
        if (it == parent) it = group;
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MOST_STONES_REMOVED_WITH_SAME_ROW_OR_COLUMN_H
