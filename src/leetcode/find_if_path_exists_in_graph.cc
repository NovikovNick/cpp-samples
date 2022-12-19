#ifndef LEETCODE_FIND_IF_PATH_EXISTS_IN_GRAPH_H
#define LEETCODE_FIND_IF_PATH_EXISTS_IN_GRAPH_H
#include <algorithm>
#include <format>
#include <iostream>
#include <numeric>
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

struct UnionFind {
  std::vector<int> parents;
  std::vector<int> ranks;
  UnionFind(const int n)
      : parents(std::vector<int>(n)), ranks(std::vector<int>(n, 1)) {
    std::iota(parents.begin(), parents.end(), 0);
  };

  int find(int i) {
    int res = parents[i];
    while (i != res) res = parents[i = res];
    return res;
  }

  void connect(const int a, const int b) {
    int a_group = find(a);
    int b_group = find(b);

    if (ranks[a_group] > ranks[b_group]) {
      parents[b_group] = a_group;
      ranks[a_group] += ranks[b_group];
      ranks[b_group] = 0;
    } else {
      parents[a_group] = b_group;
      ranks[b_group] += ranks[a_group];
      ranks[a_group] = 0;
    }
  }
};
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
  bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
    UnionFind uf(n);
    for (const auto& edge : edges) uf.connect(edge[0], edge[1]);
    return uf.find(src) == uf.find(dst);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_IF_PATH_EXISTS_IN_GRAPH_H
