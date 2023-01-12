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
    std::vector<int> res;
    // iterativePreorder(root, res);
    recursivePreorder(root, res);
    return res;
  }
  vector<int> inorderTraversal(TreeNode *root) {
    if (root == nullptr) return {};
    std::vector<int> res;
    // recursiveInorder(root, res);
    iterativeInorder(root, res);
    return res;
  }
  vector<int> postorderTraversal(TreeNode *root) {
    if (root == nullptr) return {};
    std::vector<int> res;
    // recursivePostorder(root, res);
    iterativePostorder(root, res);
    return res;
  }

 private:
  void iterativePreorder(TreeNode *root, std::vector<int> &res) {
    std::stack<TreeNode *> stack;
    stack.push(root);
    TreeNode *node;
    while (!stack.empty()) {
      node = stack.top();
      stack.pop();

      res.emplace_back(node->val);
      if (node->right) stack.push(node->right);
      if (node->left) stack.push(node->left);
    }
  }

  void iterativeInorder(TreeNode *node, std::vector<int> &res) {
    std::stack<TreeNode *> stack;
    while (!stack.empty() || node != nullptr) {
      if (node != nullptr) {
        stack.push(node);
        node = node->left;
      } else {
        node = stack.top();
        stack.pop();
        res.emplace_back(node->val);
        node = node->right;
      }
    }
  }

  void iterativePostorder(TreeNode *node, std::vector<int> &res) {
    std::stack<TreeNode *> stack;
    TreeNode *last_visited_node = nullptr;
    while (!stack.empty() || node != nullptr) {
      if (node != nullptr) {
        stack.push(node);
        node = node->left;
      } else {
        auto peek_node = stack.top();
        if (peek_node->right && last_visited_node != peek_node->right) {
          node = peek_node->right;
        } else {
          res.emplace_back(peek_node->val);
          last_visited_node = peek_node;
          stack.pop();
        }
      }
    }
  }

  void recursivePreorder(TreeNode *node, std::vector<int> &res) {
    if (node == nullptr) return;
    res.emplace_back(node->val);
    if (node->left) recursivePreorder(node->left, res);
    if (node->right) recursivePreorder(node->right, res);
  }

  void recursiveInorder(TreeNode *node, std::vector<int> &res) {
    if (node == nullptr) return;
    if (node->left) recursiveInorder(node->left, res);
    res.emplace_back(node->val);
    if (node->right) recursiveInorder(node->right, res);
  }

  void recursivePostorder(TreeNode *node, std::vector<int> &res) {
    if (node == nullptr) return;
    if (node->left) recursivePostorder(node->left, res);
    if (node->right) recursivePostorder(node->right, res);
    res.emplace_back(node->val);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_BINARY_TREE_PREORDER_TRAVERSAL_H
