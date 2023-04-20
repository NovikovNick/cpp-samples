#ifndef LEETCODE_MAXIMUM_WIDTH_OF_BINARY_TREE_H
#define LEETCODE_MAXIMUM_WIDTH_OF_BINARY_TREE_H
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
  int widthOfBinaryTree(TreeNode *root) {
    int res = 0;
    std::queue<std::pair<uint64_t, TreeNode *>> nodes;
    nodes.push({0, root});
    int size, begin, end;
    while (nodes.size()) {
      size = nodes.size();
      begin = end = 0;
      while (--size >= 0) {
        auto [i, node] = nodes.front();
        nodes.pop();

        if (begin == 0) begin = i;
        end = i;

        if (node->left) nodes.push({2 * i + 1, node->left});
        if (node->right) nodes.push({2 * i + 2, node->right});
      }
      res = std::max(res, end - begin + 1);
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_WIDTH_OF_BINARY_TREE_H
