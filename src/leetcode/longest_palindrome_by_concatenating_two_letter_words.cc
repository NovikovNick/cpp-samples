#ifndef LEETCODE_LONGEST_PALINDROME_BY_CONCATENATING_TWO_LETTER_WORDS_H
#define LEETCODE_LONGEST_PALINDROME_BY_CONCATENATING_TWO_LETTER_WORDS_H
#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace leetcode {

using namespace std;

class Solution {
 public:
  int longestPalindrome(vector<string>& words) {
    std::vector<int> letters(26);
    std::unordered_map<std::string, int> countedWords;
    std::unordered_map<std::string, int> pairs;

    for (auto word : words) {
      char a = word[0];
      char b = word[1];
      //std::cout << std::format("Checking {} & {}. ", a, b);
      if (a == b) {
        //std::cout << std::format("Letters are the same.\n");
        ++letters[static_cast<int>(a) - static_cast<int>('a')];
      } else {
        //std::cout << std::format("Letters are different. ");
        std::string str("");
        str += b;
        str += a;
        auto& count = countedWords[str];
        if (count == 0) {
          //std::cout << std::format("No {} pair for {}.\n", str, word);
          ++countedWords[word];
        } else {
          //std::cout << std::format("Found {} pair for {}.\n", str, word);
          auto pair = str + word;
          --countedWords[str];
          std::sort(pair.begin(), pair.end());
          ++pairs[pair];
        }
      }
    }
    int same_letters_count = 0;
    int pair_counts = 0;
    bool hasMid = false;
    for (int i = 0; auto it : letters) {
      same_letters_count += it / 2;
      if (!hasMid) {
        hasMid = it % 2 != 0;
      }
      //std::cout << std::format("{} = {}\n", static_cast<char>(static_cast<int>('a') + i), it);
      ++i;
    }

    for (auto [key, val] : pairs) {
      pair_counts += val;
    }

    /*std::cout << std::format("same letters {} => {} \n", same_letters_count,
                             same_letters_count * 4);
    std::cout << std::format("pairs        {} => {} \n", pair_counts,
                             pair_counts * 4);
    std::cout << std::format("mid          {} => {} \n",
                             static_cast<int>(hasMid),
                             static_cast<int>(hasMid) * 2);*/
    
    return static_cast<int>(hasMid) * 2 + (same_letters_count + pair_counts) * 4;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LONGEST_PALINDROME_BY_CONCATENATING_TWO_LETTER_WORDS_H
