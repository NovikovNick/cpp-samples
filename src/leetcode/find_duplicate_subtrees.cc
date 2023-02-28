#ifndef LEETCODE_FIND_DUPLICATE_SUBTREES_H
#define LEETCODE_FIND_DUPLICATE_SUBTREES_H
#include <algorithm>
#include <format>
#include <iostream>
#include <stack>
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

struct Subtree {
  TreeNode *subtree;
  size_t size;
  Subtree(TreeNode *subtree) : subtree(subtree), size(1){};
};

class Solution {
  static const size_t kOffset = 200;
  static const size_t kHashtableSize = 400;

  std::vector<std::vector<Subtree>> hashtable;

 public:
  Solution() : hashtable(std::vector<std::vector<Subtree>>(kHashtableSize)) {}

  static bool compare(const Subtree &lhs, const Subtree &rhs) {
    if (lhs.subtree->val < rhs.subtree->val) return true;
    if (lhs.subtree->val == rhs.subtree->val) return lhs.size > rhs.size;
    return false;
  };

  static bool isEqual(const Subtree &lhs, const Subtree &rhs) {
    std::stack<TreeNode *> lhs_stack, rhs_stack;
    lhs_stack.push(lhs.subtree);
    rhs_stack.push(rhs.subtree);
    while (!lhs_stack.empty() && !rhs_stack.empty()) {
      auto lhs_node = lhs_stack.top();
      lhs_stack.pop();
      auto rhs_node = rhs_stack.top();
      rhs_stack.pop();

      if (lhs_node == nullptr || rhs_node == nullptr) {
        if (rhs_node == lhs_node) {
          continue;
        } else {
          return false;
        }
      }
      if (lhs_node->val != rhs_node->val) return false;

      lhs_stack.push(lhs_node->right);
      lhs_stack.push(lhs_node->left);
      rhs_stack.push(rhs_node->right);
      rhs_stack.push(rhs_node->left);
    }
    return lhs_stack.size() == rhs_stack.size();
  };

  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    vector<TreeNode *> res(1);
    if (root == nullptr) return res;

    initHashtable(root);
    size_t size = 0;
    for (auto &subtrees : hashtable) {
      if (subtrees.size() < 2) continue;
      std::sort(subtrees.begin(), subtrees.end(), Solution::compare);

      for (int i = 1; i < subtrees.size(); ++i) {
        if (subtrees[i].subtree->val != subtrees[i - 1].subtree->val) continue;
        if (subtrees[i].size != subtrees[i - 1].size) continue;
        if (subtrees[i].size < size) continue;

        if (isEqual(subtrees[i], subtrees[i - 1])) {
          res[0] = subtrees[i].subtree;
          size = subtrees[i].size;
        }
      }
    }
    return res;
  }

  size_t initHashtable(TreeNode *node) {
    auto &subtrees = hashtable[node->val + kOffset];
    subtrees.emplace_back(node);
    auto &size = (*subtrees.rbegin()).size;
    if (node->left) size += initHashtable(node->left);
    if (node->right) size += initHashtable(node->right);
    return size;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_DUPLICATE_SUBTREES_H
