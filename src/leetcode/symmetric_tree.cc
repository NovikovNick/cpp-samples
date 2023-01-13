#ifndef LEETCODE_SYMMETRIC_TREE_H
#define LEETCODE_SYMMETRIC_TREE_H
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
  bool isSymmetric(TreeNode *root) {
    std::queue<TreeNode *> queue;
    queue.push(root);

    std::vector<TreeNode *> level;

    while (!queue.empty()) {
      int size = queue.size();
      level.clear();
      while (--size >= 0) {
        auto node = queue.front();
        queue.pop();
        level.push_back(node);

        if (node) {
          queue.push(node->left);
          queue.push(node->right);
        }
      }

      auto fst = level.begin();
      auto snd = level.end() - 1;
      while (fst < snd) {
        if (!(*fst == nullptr && *snd == nullptr)) {
          if (*fst == nullptr && *snd != nullptr) return false;
          if (*fst != nullptr && *snd == nullptr) return false;
          if ((*fst)->val != (*snd)->val) return false;
        };
        ++fst;
        --snd;
      }
    }
    return true;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SYMMETRIC_TREE_H
