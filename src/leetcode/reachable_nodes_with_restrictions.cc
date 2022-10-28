#ifndef LEETCODE_REACHABLE_NODES_WITH_RESTRICTIONS_H
#define LEETCODE_REACHABLE_NODES_WITH_RESTRICTIONS_H
#include <algorithm>
#include <deque>
#include <format>
#include <iostream>
#include <unordered_map>
#include <vector>

namespace leetcode {

using namespace std;

struct Node {
  std::vector<int> adjacents;
  bool restricted = false;
  bool visited = false;
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
  int reachableNodes(int n, vector<vector<int>>& edges,
                     vector<int>& restricted) {
    std::unordered_map<int, Node> nodes;
    for (int i = 0; i < n; ++i) {
      nodes[n] = Node();
    }
    for (auto edge : edges) {
      nodes[edge[0]].adjacents.push_back(edge[1]);
      nodes[edge[1]].adjacents.push_back(edge[0]);
    }
    for (auto restrict : restricted) {
      nodes[restrict].restricted = true;
    }
    std::deque<int> reachable;
    reachable.push_back(0);
    int res = 0;
    while (!reachable.empty()) {
      auto index = reachable.back();
      reachable.pop_back();
      auto& node = nodes[index];
      node.visited = true;
      ++res;
      // std::cout << std::format("Checking {}\n", index);
      for (auto adjIndex : node.adjacents) {
        auto& adjacent = nodes[adjIndex];
        if (!adjacent.visited && !adjacent.restricted) {
          reachable.push_back(adjIndex);
        }
      }
    }
    return res;
  }
};

}  // namespace leetcode
#endif  // LEETCODE_REACHABLE_NODES_WITH_RESTRICTIONS_H
