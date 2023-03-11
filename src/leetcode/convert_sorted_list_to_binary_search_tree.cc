#ifndef LEETCODE_CONVERT_SORTED_LIST_TO_BINARY_SEARCH_TREE_H
#define LEETCODE_CONVERT_SORTED_LIST_TO_BINARY_SEARCH_TREE_H
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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
  TreeNode *sortedListToBST(ListNode *head) {
    std::vector<int> arr;
    while (head) {
      arr.push_back(head->val);
      head = head->next;
    }
    return buildBTS(0, arr.size() - 1, arr);
  }
  TreeNode *buildBTS(const int low, const int high,
                     const std::vector<int> &arr) {
    if (low > high) return nullptr; 
    int mid = low + ((high - low) >> 1);
    auto res = new TreeNode(arr[mid]);
    auto left = buildBTS(low, mid - 1, arr);
    auto right = buildBTS(mid + 1, high, arr);
    if (left) res->left = left;
    if (right) res->right = right;
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CONVERT_SORTED_LIST_TO_BINARY_SEARCH_TREE_H
