#ifndef LEETCODE_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H
#define LEETCODE_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H
#include <algorithm>
#include <format>
#include <iostream>
#include <queue>
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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (root == nullptr) return {};

    std::vector<std::vector<int>> res;
    std::queue<TreeNode *> queue;
    queue.push(root);
    int level = 0;
    while (!queue.empty()) {
      int size = queue.size();
      res.push_back({});
      while (--size >= 0) {
        auto node = queue.front();
        res[level].push_back(node->val);
        queue.pop();
        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
      }
      if (level % 2 != 0) std::reverse(res[level].begin(), res[level].end());
      ++level;
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H
