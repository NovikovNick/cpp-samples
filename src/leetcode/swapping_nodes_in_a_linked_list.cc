#ifndef LEETCODE_SWAPPING_NODES_IN_A_LINKED_LIST_H
#define LEETCODE_SWAPPING_NODES_IN_A_LINKED_LIST_H
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
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* swapNodes(ListNode* head, int k) {
    int n = 0;
    auto curr = head;

    ListNode* forward;
    while (curr) {
      if (++n == k) forward = curr;
      curr = curr->next;
    }
    //if (n == 1) return head;

    curr = head;
    for (int i = 1; i <= (n - k); ++i) curr = curr->next;

    std::swap(forward->val, curr->val);

    return head;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SWAPPING_NODES_IN_A_LINKED_LIST_H
