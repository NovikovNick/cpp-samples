#ifndef LEETCODE_NUMBER_OF_OPERATIONS_TO_MAKE_NETWORK_CONNECTED_H
#define LEETCODE_NUMBER_OF_OPERATIONS_TO_MAKE_NETWORK_CONNECTED_H
#include <algorithm>
#include <format>
#include <iostream>
#include <numeric>
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

class UnionFind {
  std::vector<int> parents;

 public:
  int group_count;
  std::vector<int> ranks;
  std::vector<int> cables;

  UnionFind(const int n)
      : group_count(n),
        parents(std::vector<int>(n)),
        ranks(std::vector<int>(n, 1)),
        cables(std::vector<int>(n)) {
    std::iota(parents.begin(), parents.end(), 0);
    for (const auto parent : parents) cables[parent];
  }

  void join(const int a, const int b) {
    int a_parent = find(a);
    int b_parent = find(b);
    if (a_parent == b_parent) {
      ++cables[a_parent];
      return;
    }

    if (ranks[a_parent] > ranks[b_parent]) {
      merge(a_parent, b_parent);
    } else {
      merge(b_parent, a_parent);
    }
  }

  void merge(const int lhs, const int rhs) {
    ranks[lhs] += ranks[rhs];
    cables[lhs] += cables[rhs] + 1;

    ranks[rhs] = cables[rhs] = 0;
    parents[rhs] = lhs;

    --group_count;
  }

  int find(int dst) {
    while (parents[dst] != dst) dst = parents[dst];
    return dst;
  }
};
class Solution {
 public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    int cables = connections.size();
    debug("There are {} cables\n", cables);
    if (cables < n - 1) return -1;

    UnionFind uf(n);
    for (const auto& it : connections) uf.join(it[0], it[1]);

    for (int i = 0; i < n; ++i) {
      if (uf.ranks[i])
        debug("Group#{}: {} computers with {} cables\n", i, uf.ranks[i],
              uf.cables[i]);
    }
    return uf.group_count - 1;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_NUMBER_OF_OPERATIONS_TO_MAKE_NETWORK_CONNECTED_H
