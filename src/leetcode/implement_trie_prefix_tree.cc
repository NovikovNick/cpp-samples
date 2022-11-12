#ifndef LEETCODE_IMPLEMENT_TRIE_PREFIX_TREE_H
#define LEETCODE_IMPLEMENT_TRIE_PREFIX_TREE_H
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

class Trie {
  struct TrieNode {
    std::vector<std::shared_ptr<TrieNode>> children;
    bool is_word;

    TrieNode()
        : children(std::vector<std::shared_ptr<TrieNode>>(26, nullptr)),
          is_word(false) {}

    bool Contains(const char ch) { return children[ch - 'a'] == nullptr; }
    void Add(const char ch) {
      children[ch - 'a'] = std::make_shared<TrieNode>();
    }
    std::shared_ptr<TrieNode> Get(const char ch) { return children[ch - 'a']; }
  };

  std::shared_ptr<TrieNode> root_;

 public:
  Trie() : root_(std::make_shared<TrieNode>()) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }

  void insert(string word) {
    auto curr = root_;
    for (const auto& ch : word) {
      if (curr->Contains(ch)) curr->Add(ch);
      curr = curr->Get(ch);
    }
    curr->is_word = true;
  }

  bool search(string word) {
    auto curr = root_;
    for (const auto& ch : word) {
      if (curr->Contains(ch)) return false;
      curr = curr->Get(ch);
    }
    return curr->is_word;
  }

  bool startsWith(string prefix) {
    auto curr = root_;
    for (const auto& ch : prefix) {
      if (curr->Contains(ch)) return false;
      curr = curr->Get(ch);
    }
    return true;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_IMPLEMENT_TRIE_PREFIX_TREE_H
