#ifndef LEETCODE_MINIMUM_ABSOLUTE_DIFFERENCE_IN_BST_H
#define LEETCODE_MINIMUM_ABSOLUTE_DIFFERENCE_IN_BST_H
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
    int minDiff = INT_MAX;
    int prevVal = -1;
 public:
  int getMinimumDifference(TreeNode *root) {
    inorderTraversal(root);
    return minDiff;
  }

  void inorderTraversal(const TreeNode *node) {
    if (!node) return;
    inorderTraversal(node->left);
    
    if (prevVal >= 0) minDiff = std::min(minDiff, node->val - prevVal);
    prevVal = node->val;

    inorderTraversal(node->right);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_ABSOLUTE_DIFFERENCE_IN_BST_H
