#ifndef LEETCODE_CHECK_COMPLETENESS_OF_A_BINARY_TREE_H
#define LEETCODE_CHECK_COMPLETENESS_OF_A_BINARY_TREE_H
#include <algorithm>
#include <format>
#include <iostream>
#include <vector>
#include <queue>

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
  bool isCompleteTree(TreeNode *root) {
    std::queue<TreeNode *> queue;
    queue.push(root);
    int size;
    bool expected_nullptr = false;
    while (!queue.empty()) {
      size = queue.size();
      while (--size >= 0) {
        auto node = queue.front();
        queue.pop();
        if (expected_nullptr && node != nullptr) return false;
        if (node == nullptr) {
          expected_nullptr = true;
        } else {
          queue.push(node->left);
          queue.push(node->right);
        }
      }
    }
    return true;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CHECK_COMPLETENESS_OF_A_BINARY_TREE_H
