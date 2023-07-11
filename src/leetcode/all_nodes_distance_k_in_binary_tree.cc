#ifndef LEETCODE_ALL_NODES_DISTANCE_K_IN_BINARY_TREE_H
#define LEETCODE_ALL_NODES_DISTANCE_K_IN_BINARY_TREE_H
#include <algorithm>
#include <format>
#include <iostream>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  std::vector<TreeNode*> parents;
  std::vector<int> res;

 public:
  Solution() : parents(std::vector<TreeNode*>(501, nullptr)), res({}) {}

  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    if (!root) return res;
    if (k == 0) return {target->val};

    dfsSetParent(root);
    dfs(k, 1, target->val, target);
    return res;
  }

  void dfsSetParent(TreeNode* node) {
    if (node->left) {
      parents[node->left->val] = node;
      dfsSetParent(node->left);
    }
    if (node->right) {
      parents[node->right->val] = node;
      dfsSetParent(node->right);
    }
  }

  void dfs(const int k, const int depth, const int parent, TreeNode* node) {
    if (depth == k) {
      if (node->left && node->left->val != parent) res.push_back(node->left->val);
      if (node->right && node->right->val != parent) res.push_back(node->right->val);
      if (parents[node->val] && parents[node->val]->val != parent)
        res.push_back(parents[node->val]->val);
    };

    if (node->left && node->left->val != parent) {
      dfs(k, depth + 1, node->val, node->left);
    }
    if (node->right && node->right->val != parent) {
      dfs(k, depth + 1, node->val, node->right);
    }
    if (parents[node->val] && parents[node->val]->val != parent) {
      dfs(k, depth + 1, node->val, parents[node->val]);
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_ALL_NODES_DISTANCE_K_IN_BINARY_TREE_H
