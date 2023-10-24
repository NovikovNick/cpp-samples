#ifndef LEETCODE_FIND_LARGEST_VALUE_IN_EACH_TREE_ROW_H
#define LEETCODE_FIND_LARGEST_VALUE_IN_EACH_TREE_ROW_H
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
  vector<int> largestValues(TreeNode *root) {
    std::vector<int> res;
    // bfs
    std::queue<TreeNode *> queue;
    if (root) queue.push(root);
    while (!queue.empty()) {
      int size = queue.size();
      int max = INT_MIN;
      while (--size >= 0) {
        auto node = queue.front();
        queue.pop();

        max = std::max(max, node->val);

        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
      }
      res.push_back(max);
    }

    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_LARGEST_VALUE_IN_EACH_TREE_ROW_H
