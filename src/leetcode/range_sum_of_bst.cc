#ifndef LEETCODE_RANGE_SUM_OF_BST_H
#define LEETCODE_RANGE_SUM_OF_BST_H
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
  int rangeSumBST(TreeNode *root, int low, int high) {
    int sum = 0;
    std::stack<TreeNode *> dfs;
    dfs.push(root);
    while (!dfs.empty()) {
      auto node = dfs.top();
      dfs.pop();
      if (node != nullptr) {
        if (node->val >= low && node->val <= high) sum += node->val;
        if (node->val > low) dfs.push(node->left);
        if (node->val < high) dfs.push(node->right);
      }
    }
    return sum;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_RANGE_SUM_OF_BST_H
