#ifndef LEETCODE_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
#define LEETCODE_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root) return {};

    // bfs
    std::queue<TreeNode *> queue;
    queue.push(root);

    std::vector<std::vector<int>> res;
    int level = 0;
    while (!queue.empty()) {
      int size = queue.size();
      res.push_back({});
      while (--size >= 0) {
        auto node = queue.front();
        queue.pop();
        res[level].push_back(node->val);
        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
      }
      ++level;
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
