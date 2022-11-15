#ifndef LEETCODE_COUNT_COMPLETE_TREE_NODES_H
#define LEETCODE_COUNT_COMPLETE_TREE_NODES_H
#include <algorithm>
#include <bitset>
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
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  int countNodes(TreeNode *root) {
    if (root == nullptr) return 0;

    int level = -1;
    auto curr = root;
    while (curr != nullptr) {
      curr = curr->left;
      ++level;
    }

    int res = 0;
    for (int i = 0; i < level; ++i) res += (1 << i);


    std::bitset<15> bitset;
    for (int i = 0, order = (1 << level); i < order; ++i) {
      bitset = i;
      curr = root;
      for (int j = level - 1; j >= 0; --j) {
        curr = bitset[j] ? curr->right : curr->left;
      }
      if (curr == nullptr) {
        return res;
      } else {
        ++res;
      }
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_COUNT_COMPLETE_TREE_NODES_H
