#ifndef LEETCODE_DESIGN_ADD_AND_SEARCH_WORDS_DATA_STRUCTURE_H
#define LEETCODE_DESIGN_ADD_AND_SEARCH_WORDS_DATA_STRUCTURE_H
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

struct TrieNode {
  bool word;
  TrieNode* data[26] = {nullptr};
  TrieNode() : word(false) {}
};

class WordDictionary {
  TrieNode* root_;

 public:
  WordDictionary() : root_(new TrieNode) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }

  void addWord(string word) {
    auto curr = root_;
    for (const auto letter : word) {
      if (curr->data[letter - 'a'] == nullptr) {
        curr->data[letter - 'a'] = new TrieNode;
      }
      curr = curr->data[letter - 'a'];
    }
    curr->word = true;
  }

  bool search(string word) { return search(root_, word); }

  bool search(TrieNode* node, const std::string& word) {
    auto curr = node;
    for (int i = 0; i < word.size(); ++i) {
      if (word[i] == '.') {
        auto substr = word.substr(i + 1);
        for (const auto& it : curr->data) {
          if (it != nullptr && search(it, substr)) return true;
        }
        return false;
      }
      if (curr->data[word[i] - 'a'] == nullptr) return false;
      curr = curr->data[word[i] - 'a'];
    }
    return curr->word;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_DESIGN_ADD_AND_SEARCH_WORDS_DATA_STRUCTURE_H
