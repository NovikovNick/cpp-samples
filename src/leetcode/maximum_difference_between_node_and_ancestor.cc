#ifndef LEETCODE_MAXIMUM_DIFFERENCE_BETWEEN_NODE_AND_ANCESTOR_H
#define LEETCODE_MAXIMUM_DIFFERENCE_BETWEEN_NODE_AND_ANCESTOR_H
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

struct N {
  TreeNode *node;
  int min, max;

  N(TreeNode *n, const int &min, const int &max)
      : node(n), min(min), max(max) {}

  N(TreeNode *n) : N(n, n->val, n->val) {}
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
  int maxAncestorDiff(TreeNode *root) {
    std::stack<N> dfs;
    dfs.emplace(root);
    int res = -1, max = -1, min = 1000001;
    while (!dfs.empty()) {
      auto node = dfs.top();
      dfs.pop();

      min = std::min(node.node->val, node.min);
      max = std::max(node.node->val, node.max);
      res = std::max(res, max - min);

      if (node.node->right) dfs.emplace(node.node->right, min, max);
      if (node.node->left) dfs.emplace(node.node->left, min, max);
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_DIFFERENCE_BETWEEN_NODE_AND_ANCESTOR_H
