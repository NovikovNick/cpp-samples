#ifndef LEETCODE_LINKED_LIST_RANDOM_NODE_H
#define LEETCODE_LINKED_LIST_RANDOM_NODE_H
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
  std::vector<int> data_;
  int cursor_;

 public:
  Solution(ListNode* head) : data_(std::vector<int>{}), cursor_(-1) {
    while (head) {
      data_.emplace_back(head->val);
      head = head->next;
    }
  }

  int getRandom() {
    cursor_ = std::rand() % data_.size();

    return data_[cursor_];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LINKED_LIST_RANDOM_NODE_H
