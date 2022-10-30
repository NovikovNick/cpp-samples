#ifndef LEETCODE_FIN_BOTTOM_LEFT_TREE_VALUE_H
#define LEETCODE_FIN_BOTTOM_LEFT_TREE_VALUE_H

#include <algorithm>
#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <format>

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
  int findBottomLeftValue(TreeNode *root) {
    std::deque<std::pair<int, TreeNode *>> stack;
    stack.push_back({0, root});
    int res = root->val;
    int maxLevel = 0;
    while (!stack.empty()) {
      auto [level, node] = stack.back();
      stack.pop_back();
      if (node == nullptr) {
        continue;
      }
      // std::cout << std::format("Checking {} : {}\n", level, node->val);
      if (level > maxLevel) {
        maxLevel = level;
        res = node->val;
      }
      stack.push_back({level + 1, node->right});
      stack.push_back({level + 1, node->left});
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIN_BOTTOM_LEFT_TREE_VALUE_H
