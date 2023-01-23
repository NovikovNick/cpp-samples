#ifndef LEETCODE_MERGE_TWO_BINARY_TREES_H
#define LEETCODE_MERGE_TWO_BINARY_TREES_H
#include <algorithm>
#include <format>
#include <iostream>
#include <vector>
#include <queue>

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
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    std::queue<TreeNode*> queue1, queue2;
    queue1.push(root1);
    queue2.push(root2);
    std::vector<TreeNode*> res;
    while (!queue1.empty()) {
      int size = queue1.size();
      while (--size >= 0) {
        auto fst = bfsExtract(queue1);
        auto snd = bfsExtract(queue2);
        res.push_back(merge(fst, snd));
      }
    }

    for (int i = 0; (i * 2 + 2) < res.size(); ++i) {
      if (res[i]) {
        res[i] = res[i * 2 + 1];
        res[i] = res[i * 2 + 2];
      }
    }
    return res[0];
  }

  TreeNode* bfsExtract(std::queue<TreeNode*>& q) {
    auto res = q.front();
    q.pop();
    if (res) {
      q.push(res->right);
      q.push(res->left);
    }
    return res;
  }

  TreeNode* merge(TreeNode* lhs, TreeNode* rhs) {
    if (lhs == nullptr && rhs == nullptr) return nullptr;
    return new TreeNode((lhs ? lhs->val : 0) + (rhs ? rhs->val : 0));
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MERGE_TWO_BINARY_TREES_H
