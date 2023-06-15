#ifndef LEETCODE_MAXIMUM_LEVEL_SUM_OF_A_BINARY_TREE_H
#define LEETCODE_MAXIMUM_LEVEL_SUM_OF_A_BINARY_TREE_H
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
  int maxLevelSum(TreeNode *root) {
    int maxLevel = 1;
    int64_t maxSum = INT_MIN;

    std::queue<TreeNode *> bfs;
    bfs.push(root);
    int level = 1;
    while (!bfs.empty()) {
      int size = bfs.size();
      int64_t sum = 0;
      while (--size >= 0) {
        const auto node = bfs.front();
        bfs.pop();

        sum += node->val;

        if (node->left) bfs.push(node->left);
        if (node->right) bfs.push(node->right);
      }

      if (sum > maxSum) {
        maxLevel = level;
        maxSum = sum;
      }

      ++level;
    }
    return maxLevel;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_LEVEL_SUM_OF_A_BINARY_TREE_H
