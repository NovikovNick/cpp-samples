#ifndef LEETCODE__H
#define LEETCODE__H
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto [h1, s1] = reverse(l1);
    auto [h2, s2] = reverse(l2);

    if (s1 < s2) std::swap(h1, h2);

    auto prev1 = h1;
    auto curr1 = h1;
    auto curr2 = h2;
    int remainder = 0;
    while (curr1 && (remainder > 0 || curr2)) {
      curr1->val += (curr2 ? curr2->val : 0) + remainder;
      remainder = curr1->val > 9 ? 1 : 0;
      curr1->val %= 10;

      prev1 = curr1;
      curr1 = curr1->next;
      if(curr2) curr2 = curr2->next;
    }

    if (remainder > 0) prev1->next = new ListNode(1);
    return reverse(h1).first;
  }

  std::pair<ListNode*, int> reverse(/*notnull*/ ListNode* origin) {
    ListNode* prevprev = nullptr;
    ListNode* prev = origin;
    ListNode* curr = origin->next;
    ListNode* next = nullptr;
    int size = 1;
    while (curr) {
      next = curr->next;

      curr->next = prev;
      prev->next = prevprev;
      prevprev = prev;
      prev = curr;
      curr = next;

      ++size;
    }
    return {prev, size};
  }
};
}  // namespace leetcode
#endif  // LEETCODE__H
