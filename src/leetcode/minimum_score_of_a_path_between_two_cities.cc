#ifndef LEETCODE_MINIMUM_SCORE_OF_A_PATH_BETWEEN_TWO_CITIES_H
#define LEETCODE_MINIMUM_SCORE_OF_A_PATH_BETWEEN_TWO_CITIES_H
#include <algorithm>
#include <format>
#include <iostream>
#include <numeric>
#include <queue>
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
  std::vector<int> groups;
  std::vector<int> dists;

 public:
  UnionFind(int n)
      : groups(std::vector<int>(n)), dists(std::vector<int>(n, INT_MAX)) {
    std::iota(groups.begin(), groups.end(), 0);
  };

  void join(const int a, const int b, int dist) {
    int a_parent = find(a);
    int b_parent = find(b);

    if (a_parent == b_parent) {
      dists[b_parent] = dists[a_parent] = std::min(dist, dists[a_parent]);
      return;
    };

    if (dists[a_parent] < dists[b_parent]) {
      groups[b] = a_parent;
      groups[b_parent] = a_parent;
      dists[b_parent] = dists[a_parent] = std::min(dist, dists[a_parent]);
    } else {
      groups[a] = b_parent;
      groups[a_parent] = b_parent;
      dists[a_parent] = dists[b_parent] = std::min(dist, dists[b_parent]);
    }
  }

  int find(int dst) {
    while (groups[dst] != dst) dst = groups[dst];
    return dst;
  }

  int getScore() { return dists[find(groups.size() - 1)]; }
};

class Solution {
 public:
  int minScore(int n, vector<vector<int>>& roads) {
    UnionFind uf(n);
    for (const auto& road : roads) {
      uf.join(road[0] - 1, road[1] - 1, road[2]);
    }
    return uf.getScore();
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_SCORE_OF_A_PATH_BETWEEN_TWO_CITIES_H
