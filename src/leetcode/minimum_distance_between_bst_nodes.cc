#ifndef LEETCODE_MINIMUM_DISTANCE_BETWEEN_BST_NODES_H
#define LEETCODE_MINIMUM_DISTANCE_BETWEEN_BST_NODES_H
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
  int res = INT_MAX, prev = -1;

 public:
  int minDiffInBST(TreeNode *root) {
    inorderTraversal(root);
    return res;
  }

  void inorderTraversal(const TreeNode *node) {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    if (prev != -1) res = std::min(res, node->val - prev);
    prev = node->val;
    inorderTraversal(node->right);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_DISTANCE_BETWEEN_BST_NODES_H
