#ifndef LEETCODE_BINARY_TREE_PREORDER_TRAVERSAL_H
#define LEETCODE_BINARY_TREE_PREORDER_TRAVERSAL_H
#include <algorithm>
#include <format>
#include <iostream>
#include <stack>
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
  vector<int> preorderTraversal(TreeNode *root) {
    if (root == nullptr) return {};

    std::stack<TreeNode *> stack;
    stack.push(root);
    std::vector<int> res;
    TreeNode *node;
    while (!stack.empty()) {
      node = stack.top();
      stack.pop();

      res.emplace_back(node->val);
      if (node->right) stack.push(node->right);
      if (node->left) stack.push(node->left);
    }

    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_BINARY_TREE_PREORDER_TRAVERSAL_H
