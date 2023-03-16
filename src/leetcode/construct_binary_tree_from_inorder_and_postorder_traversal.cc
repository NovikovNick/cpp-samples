#ifndef LEETCODE_CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_TRAVERSAL_H
#define LEETCODE_CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_TRAVERSAL_H
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
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return buildTree(0, inorder.size(), 0, inorder, postorder);
  }

  TreeNode* buildTree(const int begin, const int end, const int offset,
                      vector<int>& inorder, vector<int>& postorder) {
    if (begin >= end) return nullptr;
    debug("range[{}...{}]: (", begin, end);
    for (int i = begin; i < end; ++i) debug("{} ", inorder[i]);
    debug(") (");
    for (int i = begin; i < end; ++i) debug("{} ", postorder[i - offset]);
    debug(") ");

    for (int i = begin; i < end; ++i) {
      if (inorder[i] != postorder[i - offset]) {
        debug("node[{}]: {}\n", i, inorder[i]);
        auto node = new TreeNode(inorder[i]);

        node->left = buildTree(begin, i, 0, inorder, postorder);
        node->right = buildTree(i + 1, end, 1, inorder, postorder);
        return node;
      }
    }
    debug("node[{}]: {}\n", end - 1, inorder[end - 1]);
    auto node = new TreeNode(inorder[end - 1]);
    if (offset == 1) {
      node->right = buildTree(begin, end - 1, offset, inorder, postorder);
    } else {
      node->left = buildTree(begin, end - 1, offset, inorder, postorder);
    }
    return node;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_TRAVERSAL_H
