#ifndef LEETCODE_BINARY_TREE_MAXIMUM_PATH_SUM_H
#define LEETCODE_BINARY_TREE_MAXIMUM_PATH_SUM_H
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
  int sum;

 public:
  Solution() : sum(-1001) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }

  int maxPathSum(TreeNode *root) {
    dfs(root);
    return sum;
  }

  int dfs(TreeNode *node) {
    auto left = node->left ? dfs(node->left) : 0;
    auto right = node->right ? dfs(node->right) : 0;
    
    sum = std::max(sum, left + right + node->val);
    sum = std::max(sum, right + node->val);
    sum = std::max(sum, left + node->val);
    sum = std::max(sum, node->val);
    auto max = std::max(node->val, node->val + std::max(left, right));

    // debug("{:5d} - left={:5d}, right={:5d}, sum={:5d}, max={:5d}\n", node->val, left, right, sum, max);
    return max;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_BINARY_TREE_MAXIMUM_PATH_SUM_H
