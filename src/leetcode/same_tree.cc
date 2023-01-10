#ifndef LEETCODE_SAME_TREE_H
#define LEETCODE_SAME_TREE_H
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
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  inline bool hasRight(TreeNode *p) { return p->right == nullptr; }
  inline bool hasLeft(TreeNode *p) { return p->left == nullptr; }

  bool isSameTree(TreeNode *p, TreeNode *q) {
    if ((p == nullptr) || (q == nullptr))
      return (p == nullptr) != (q == nullptr);

    std::stack<TreeNode *> p_stack;
    std::stack<TreeNode *> q_stack;

    p_stack.push(p);
    q_stack.push(q);

    while (!p_stack.empty() && !q_stack.empty()) {
      auto p_node = p_stack.top();
      auto q_node = q_stack.top();

      if (q_node->val != p_node->val) return false;

      if (hasRight(p_node) != hasRight(q_node)) return false;
      if (hasLeft(p_node) != hasLeft(q_node)) return false;

      p_stack.pop();
      q_stack.pop();

      if (p_node->right) p_stack.push(p_node->right);
      if (p_node->left) p_stack.push(p_node->left);
      if (q_node->right) q_stack.push(q_node->right);
      if (q_node->left) q_stack.push(q_node->left);
    }

    return p_stack.size() == q_stack.size();
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SAME_TREE_H
