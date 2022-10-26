#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#ifndef LEETCODE_BINARY_TREE_PATHS_H
#define LEETCODE_BINARY_TREE_PATHS_H

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
  vector<string> binaryTreePaths(TreeNode *root) {
    std::deque<std::pair<std::string, TreeNode *>> queue{
        std::make_pair("", root)};
    std::vector<std::string> res;

    while (!queue.empty()) {
      auto [str, curr] = queue.back();
      queue.pop_back();

      str = str == "" ? std::to_string(curr->val)
                      : str + "->" + std::to_string(curr->val);

      bool hasLeft = curr->left != nullptr;
      bool hasRight = curr->right != nullptr;

      if (!hasLeft && !hasRight) {
        res.push_back(str);
      } else {
        if (hasRight) queue.push_back(std::make_pair(str, curr->right));
        if (hasLeft) queue.push_back(std::make_pair(str, curr->left));
      }
    }
    return res;
  }
};
}  // namespace leetcode

#endif  // LEETCODE_BINARY_TREE_PATHS_H
