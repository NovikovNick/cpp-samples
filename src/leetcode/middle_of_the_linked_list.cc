#ifndef LEETCODE_MIDDLE_OF_THE_LINKED_LIST_H
#define LEETCODE_MIDDLE_OF_THE_LINKED_LIST_H
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
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  /*ListNode* middleNode(ListNode* head) {
    int n = 0;
    auto curr = head, res = head;
    while (curr != nullptr) {
      curr = curr->next;
      ++n;
      if (n % 2 == 0) res = res->next;
    }
    return res;
  }*/

  ListNode* middleNode(ListNode* head) {
    auto fast = head, slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MIDDLE_OF_THE_LINKED_LIST_H
