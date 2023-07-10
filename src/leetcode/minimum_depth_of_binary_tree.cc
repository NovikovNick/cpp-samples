#ifndef LEETCODE_MINIMUM_DEPTH_OF_BINARY_TREE_H
#define LEETCODE_MINIMUM_DEPTH_OF_BINARY_TREE_H
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
 public:
  int min_depth = INT_MAX;

  int minDepth(TreeNode *root) {
    if (root) dfs(1, root);
    return min_depth == INT_MAX ? 0 : min_depth;
  }
  void dfs(const int depth, TreeNode *node) {
    if (!node->left && !node->right) {
      min_depth = std::min(min_depth, depth);
      return;
    }

    if (node->left) dfs(depth + 1, node->left);
    if (node->right) dfs(depth + 1, node->right);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_DEPTH_OF_BINARY_TREE_H
