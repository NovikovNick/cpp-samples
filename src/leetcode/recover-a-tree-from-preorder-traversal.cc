#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#ifndef LEETCODE_RECOVER_A_TREE_FROM_PREORDER_TRAVERSAL_H
#define LEETCODE_RECOVER_A_TREE_FROM_PREORDER_TRAVERSAL_H

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

template <typename Iter>
std::tuple<int, TreeNode*, Iter> parseValAndDepth(Iter start, Iter end) {
  int depth = 0;
  auto it = start;
  int val = 0;
  for (; it != end; ++it) {
    char curChar = *it;
    if (curChar == '-') {
      if (val != 0) {
        break;
      }
      depth++;
    } else {
      val = 10 * val + (static_cast<int>(curChar) - static_cast<int>('0'));
    }
  }
  return std::make_tuple(depth, new TreeNode(val), it);
}

class Solution {
 public:
  TreeNode *recoverFromPreorder(string traversal) {
    std::deque<TreeNode *> stack;
    TreeNode *root = nullptr;
    TreeNode *parent = nullptr;
    int prevDepth = 0;
    auto begin = traversal.cbegin();
    while (begin != traversal.cend()) {
      auto [depth, node, iter] = parseValAndDepth(begin, traversal.cend());
      begin = iter;
      if (depth == 0) {
        root = node;
      } else if (prevDepth < depth) {
        parent->left = node;
      } else {
        int distance = prevDepth - depth;
        while (--distance >= -1) {
          stack.pop_back();
        }
        parent = stack.back();
        parent->right = node;
      }
      stack.push_back(node);
      parent = node;
      prevDepth = depth;
    }
    return root;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_RECOVER_A_TREE_FROM_PREORDER_TRAVERSAL_H
