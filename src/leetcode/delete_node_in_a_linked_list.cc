#ifndef LEETCODE_DELETE_NODE_IN_A_LINKED_LIST_H
#define LEETCODE_DELETE_NODE_IN_A_LINKED_LIST_H
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

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  void deleteNode(ListNode* node) {
    auto next_node = node->next;
    node->val = next_node->val;
    node->next = next_node->next;
    delete next_node;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_DELETE_NODE_IN_A_LINKED_LIST_H
