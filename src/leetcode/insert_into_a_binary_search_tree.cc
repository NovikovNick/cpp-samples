#ifndef LEETCODE_INSERT_INTO_A_BINARY_SEARCH_TREE_H
#define LEETCODE_INSERT_INTO_A_BINARY_SEARCH_TREE_H
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
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (!root) return new TreeNode(val);
    insert(root, val);
    return root;
  }

  void insert(TreeNode *node, int val) {
    if (val > node->val) {
      if (node->right) {
        insert(node->right, val);
      } else {
        node->right = new TreeNode(val);
      }
    }
    if (val < node->val) {
      if (node->left) {
        insert(node->left, val);
      } else {
        node->left = new TreeNode(val);
      }
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_INSERT_INTO_A_BINARY_SEARCH_TREE_H
