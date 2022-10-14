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
std::tuple<int, int, Iter> parseValAndDepth(Iter start, Iter end) {
  int depth = 0;
  std::string valStr;
  auto it = start;
  for (; it != end; ++it) {
    char curChar = *it;
    if (curChar == '-') {
      if (!valStr.empty()) {
        break;
      }
      depth++;
    } else {
      valStr += curChar;
    }
  }
  return std::make_tuple(depth, std::stoi(valStr), it);
}

class Solution {
 public:
  TreeNode *recoverFromPreorder(string traversal) {
    std::unordered_map<TreeNode *, TreeNode *> parents;
    TreeNode *root = nullptr;
    TreeNode *parent = nullptr;
    int prevDepth = 0;
    auto begin = traversal.cbegin();
    while (begin != traversal.cend()) {
      auto [depth, value, iter] = parseValAndDepth(begin, traversal.cend());
      begin = iter;
      TreeNode *node = new TreeNode(value);
      if (depth == 0) {
        root = node;
      } else if (prevDepth < depth) {
        parent->left = node;
      } else {
        int distance = prevDepth - depth;
        while (--distance >= -1) {
          parent = parents[parent];
        }
        parent->right = node;
      }
      parents.insert({node, parent});
      parent = node;
      prevDepth = depth;
    }
    return root;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_RECOVER_A_TREE_FROM_PREORDER_TRAVERSAL_H
