#ifndef LEETCODE_CONCATENATED_WORDS_H
#define LEETCODE_CONCATENATED_WORDS_H
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

struct Trie {
  const static int letter_count = 26;
  std::vector<std::shared_ptr<Trie>> hash;
  bool is_word;

  Trie()
      : hash(std::vector<std::shared_ptr<Trie>>(letter_count, nullptr)),
        is_word(false){};

  void add(const std::string& word) {
    if (hash[index(word[0])] == nullptr)
      hash[index(word[0])] = std::make_shared<Trie>();
    auto curr = hash[index(word[0])];
    for (int i = 1; i < word.size(); ++i) {
      if (curr->hash[index(word[i])] == nullptr)
        curr->hash[index(word[i])] = std::make_shared<Trie>();
      curr = curr->hash[index(word[i])];
    }
    curr->is_word = true;
  }

  inline int index(const char ch) { return ch - 'a'; }
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
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    auto trie = std::make_shared<Trie>();

    for (const auto& word : words) trie->add(word);

    std::vector<std::string> res;
    for (const auto& word : words) {
      if (find(0, word, trie) >= 2) res.push_back(word);
    }
    return res;
  }

  int find(int i, const std::string& word, std::shared_ptr<Trie> trie) {
    if (i == word.size()) {
      //debug("end of {}\n", word);
      return 0;
    };

    auto curr = trie;
    for (; i < word.size(); ++i) {
      //debug("{}", word[i]);
      curr = curr->hash[word[i] - 'a'];
      if (curr == nullptr) break;
      if (curr->is_word) {
        //debug("\n");
        int count = find(i + 1, word, trie);
        if (count < 0) {
          //debug(" - not a word\n");
        } else {
          //debug("1 + {}\n", count);
          return 1 + count;
        }
      }
    }
    return -1;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CONCATENATED_WORDS_H
