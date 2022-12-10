#ifndef LEETCODE_MAXIMUM_PRODUCT_OF_SPLITTED_BINARY_TREE_H
#define LEETCODE_MAXIMUM_PRODUCT_OF_SPLITTED_BINARY_TREE_H
#include <algorithm>
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
  int MOD = 1000000007;
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  int maxProduct(TreeNode *root) {
    dfsSum(root);
    uint64_t max_product = 0;
    dfsMaxProduct(root, root->val, max_product);
    return max_product % MOD;
  }

  int dfsSum(TreeNode *n) {
    return n->val += ((n->left) ? dfsSum(n->left) : 0) +
                     ((n->right) ? dfsSum(n->right) : 0);
  }

  void dfsMaxProduct(TreeNode *n, const uint64_t &sum, uint64_t &max_product) {
    max_product = max(max_product, (sum - n->val) * n->val);
    if (n->left) dfsMaxProduct(n->left, sum, max_product);
    if (n->right) dfsMaxProduct(n->right, sum, max_product);
  }

  uint64_t max(const uint64_t &a, const uint64_t &b) { return a > b ? a : b; }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_PRODUCT_OF_SPLITTED_BINARY_TREE_H
