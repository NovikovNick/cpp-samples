#ifndef LEETCODE_COUNT_UNREACHABLE_PAIRS_OF_NODES_IN_AN_UNDIRECTED_GRAPH_H
#define LEETCODE_COUNT_UNREACHABLE_PAIRS_OF_NODES_IN_AN_UNDIRECTED_GRAPH_H
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

 public:
  std::vector<int> ranks;

  UnionFind(const int n)
      : parents(std::vector<int>(n)), ranks(std::vector<int>(n, 1)) {
    std::iota(parents.begin(), parents.end(), 0);
  }

  void join(const int a, const int b) {
    int a_parent = find(a), b_parent = find(b);
    if (a_parent == b_parent) return;
    if (ranks[a_parent] > ranks[b_parent]) {
      merge(a_parent, b_parent);
    } else {
      merge(b_parent, a_parent);
    }
  }

  void merge(const int lhs, const int rhs) {
    parents[rhs] = lhs;
    ranks[lhs] += ranks[rhs];
    ranks[rhs] = 0;
  }

  /*int find(int i) {
    while (i != parents[i]) i = parents[i];
    return i;
  }*/

  int find(int i) {
    if (i != parents[i]) parents[i] = find(parents[i]);
    return parents[i];
  }
};

class Solution {
 public:
  long long countPairs(int n, vector<vector<int>>& edges) {
    UnionFind uf(n);
    for (const auto& it : edges) uf.join(it[0], it[1]);

    long long res = 0;
    for (const auto rank : uf.ranks) {
      n -= rank;
      res += rank * n;
      debug("{} * {} += {}\n", rank, n, res);
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_COUNT_UNREACHABLE_PAIRS_OF_NODES_IN_AN_UNDIRECTED_GRAPH_H
