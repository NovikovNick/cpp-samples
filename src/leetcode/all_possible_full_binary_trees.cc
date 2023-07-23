#ifndef LEETCODE_ALL_POSSIBLE_FULL_BINARY_TREES_H
#define LEETCODE_ALL_POSSIBLE_FULL_BINARY_TREES_H
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
 public:
  vector<TreeNode *> allPossibleFBT(int n) {
    if (!(n & 1)) return {};

    std::vector<TreeNode *> res(n);
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_ALL_POSSIBLE_FULL_BINARY_TREES_H
