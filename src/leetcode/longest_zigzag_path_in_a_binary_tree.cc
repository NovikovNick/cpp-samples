#ifndef LEETCODE_LONGEST_ZIGZAG_PATH_IN_A_BINARY_TREE_H
#define LEETCODE_LONGEST_ZIGZAG_PATH_IN_A_BINARY_TREE_H
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
  int res = 0;

 public:
  int longestZigZag(TreeNode *root) {
    if (root) dfs(0, 0, root);
    return res;
  }

  void dfs(const int left, const int right, TreeNode* node) {
    res = std::max(res, right);
    res = std::max(res, left);
    if (node->left) dfs(0, right + 1, node->left);
    if (node->right) dfs(left + 1, 0, node->right);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LONGEST_ZIGZAG_PATH_IN_A_BINARY_TREE_H
