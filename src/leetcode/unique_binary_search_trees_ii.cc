#ifndef LEETCODE_UNIQUE_BINARY_SEARCH_TREES_II_H
#define LEETCODE_UNIQUE_BINARY_SEARCH_TREES_II_H
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
  vector<TreeNode *> generateTrees(int n) {
    std::vector<TreeNode *> res;
    auto node = new TreeNode(1);
    backtracking(node, node, n, res);
    return res;
  }

  void backtracking(TreeNode *head,
                    TreeNode *tail,
                    const int n,
                    std::vector<TreeNode *> &res) {
    if (tail->val == n) {
      auto copy_head = copy(head);
      setValuePreorder(n, copy_head); 
      res.push_back(copy_head);
      return;
    }

    auto next = new TreeNode(tail->val + 1);

    tail->left = next;
    backtracking(head, next, n, res);
    tail->left = nullptr;

    tail->right = next;
    backtracking(head, next, n, res);
  }

  TreeNode *copy(TreeNode *root) {
    auto res = new TreeNode(root->val);

    if (root->left) res->left = copy(root->left);
    if (root->right) res->right = copy(root->right);

    return res;
  }

  int setValuePreorder(int i, TreeNode *node) {
    if(node->left) i = setValuePreorder(i - 1, node->left);
    node->val = i;
    if(node->right) i = setValuePreorder(i - 1, node->right);
    return i;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_UNIQUE_BINARY_SEARCH_TREES_II_H
