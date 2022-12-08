#ifndef LEETCODE_LEAF_SIMILAR_TREES_H
#define LEETCODE_LEAF_SIMILAR_TREES_H
#include <algorithm>
#include <format>
#include <iostream>
#include <vector>

template <typename... Args>
void debug(const std::string_view &str, Args &&...args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
  using T = TreeNode *;

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
  bool leafSimilar(T root1, T root2) {
    std::vector<int> arr1, arr2;
    dfs(root1, arr1);
    dfs(root2, arr2);
    return arr1 == arr2;
  }
  void dfs(T node, std::vector<int> &res) {
    if (node->left) dfs(node->left, res);
    if (node->right) dfs(node->right, res);
    if (!node->right && !node->left) res.push_back(node->val);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LEAF_SIMILAR_TREES_H
