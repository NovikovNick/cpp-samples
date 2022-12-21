#ifndef LEETCODE_POSSIBLE_BIPARTITION_H
#define LEETCODE_POSSIBLE_BIPARTITION_H
#include <algorithm>
#include <format>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>
#include <queue>

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
  int group_count;
  UnionFind(const int n)
      : group_count(n),
        parents(std::vector<int>(n)),
        ranks(std::vector<int>(n, 1)) {
    std::iota(parents.begin(), parents.end(), 0);
  }

  int find(int index) {
    while (parents[index] != index) index = parents[index];
    return index;
  }

  void connect(const int a, const int b) {
    int a_parent = find(a - 1);
    int b_parent = find(b - 1);

    if (a_parent == b_parent) return;

    if (ranks[a_parent] > ranks[b_parent]) {
      parents[b_parent] = a_parent;
      ranks[a_parent] += ranks[b_parent];
      ranks[b_parent] = 0;
    } else {
      parents[a_parent] = b_parent;
      ranks[b_parent] += ranks[a_parent];
      ranks[a_parent] = 0;
    }

    --group_count;
  }
};

class Solution {
 public:
  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    std::vector<std::vector<int>> adj(n + 1);
    for (const auto& dislike : dislikes) {
      adj[dislike[0]].push_back(dislike[1]);
      adj[dislike[1]].push_back(dislike[0]);
    }

    std::vector<int> color(n + 1, -1);  // 0 stands for red and 1 stands for blue.
    for (int i = 1; i <= n; i++) {
      if (color[i] == -1) {
        // For each pending component, run BFS.
        if (!bfs(i, adj, color))
          // Return false, if there is conflict in the component.
          return false;
      }
    }
    return true;
  }

  bool bfs(int source, vector<vector<int>>& adj, vector<int>& color) {
    std::queue<int> q;
    q.push(source);
    color[source] = 0;  // Start with marking source as `RED`.

    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto& neighbor : adj[node]) {
        // If there is a conflict, return false.
        if (color[neighbor] == color[node]) return false;
        if (color[neighbor] == -1) {
          color[neighbor] = 1 - color[node];
          q.push(neighbor);
        }
      }
    }
    return true;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_POSSIBLE_BIPARTITION_H
