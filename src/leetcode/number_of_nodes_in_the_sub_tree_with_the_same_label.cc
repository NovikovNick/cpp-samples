#ifndef LEETCODE_NUMBER_OF_NODES_IN_THE_SUB_TREE_WITH_THE_SAME_LABEL_H
#define LEETCODE_NUMBER_OF_NODES_IN_THE_SUB_TREE_WITH_THE_SAME_LABEL_H
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
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    std::vector<std::vector<int>> nodes(n);

    for (const auto& edge : edges) {
      nodes[edge[0]].push_back(edge[1]);
      nodes[edge[1]].push_back(edge[0]);
    }
    std::vector<int> res(n);
    dfs(-1, 0, nodes, labels, res);
    return res;
  }

  std::vector<int> dfs(const int parent_index, const int index,
                       std::vector<std::vector<int>>& nodes,
                       std::string& labels, std::vector<int>& res) {
    std::vector<int> hash(26, 0);
    ++hash[labels[index] - 'a'];
    for (const auto& child_index : nodes[index]) {
      if (child_index == parent_index) continue;
      merge(dfs(index, child_index, nodes, labels, res), hash);
    }

    res[index] = hash[labels[index] - 'a'];

    return hash;
  }

  void merge(const std::vector<int>& src, std::vector<int>& dst) {
    for (int i = 0; i < dst.size(); ++i) dst[i] += src[i];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_NUMBER_OF_NODES_IN_THE_SUB_TREE_WITH_THE_SAME_LABEL_H
