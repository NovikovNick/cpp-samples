#ifndef LEETCODE__H
#define LEETCODE__H
#include <algorithm>
#include <format>
#include <iostream>
#include <numeric>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

class UnionFind {
  std::vector<int> parents;
  int groupCount;

 public:
  UnionFind(int n) : parents(std::vector<int>(n)), groupCount(n) {
    std::iota(parents.begin(), parents.end(), 0);
  }

  void add(const int a, const int b) {
    const auto a_parent = find(a);
    const auto b_parent = find(b);

    if (a_parent != b_parent) {
      parents[b_parent] = a_parent;
      --groupCount;
    }
  }

  int find(const int a) {
    if (a != parents[a]) parents[a] = find(parents[a]);
    return parents[a];
  }

  int getGroupCount() const { return groupCount; }
};

class Solution {
 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    UnionFind uf(n);
    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < n; ++col) {
        if (row != col && isConnected[row][col]) uf.add(row, col);
      }
    }
    return uf.getGroupCount();
  }
};
}  // namespace leetcode
#endif  // LEETCODE__H
