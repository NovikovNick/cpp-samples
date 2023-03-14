#ifndef LEETCODE_SUM_ROOT_TO_LEAF_NUMBERS_H
#define LEETCODE_SUM_ROOT_TO_LEAF_NUMBERS_H
#include <algorithm>
#include <format>
#include <iostream>
#include <stack>
#include <string>
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
  int sumNumbers(TreeNode *root) {
    std::string path;
    return dfs(root, path);
  }

  int dfs(TreeNode *node, std::string &path) {
    int res = 0;
    if (node == nullptr) return res;
    path.append(std::to_string(node->val));

    if (node->left == nullptr && node->right == nullptr) {
      res = std::stoi(path);
    } else {
      res += dfs(node->left, path);
      res += dfs(node->right, path);
    }
    path.pop_back();
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SUM_ROOT_TO_LEAF_NUMBERS_H
