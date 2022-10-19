#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#ifndef LEETCODE_INTEGER_TO_ROMAN_H
#define LEETCODE_INTEGER_TO_ROMAN_H

namespace leetcode {

using namespace std;

class Solution {
 public:
  string intToRoman(int num) {

    std::vector<std::pair<int, std::string>> dictionary{
        {1000, "M"}, 
        {900, "CM"}, 
        {500, "D"}, 
        {400, "CD"},
        {100, "C"},  
        {90, "XC"},  
        {50, "L"}, 
        {40, "XL"},
        {10, "X"},   
        {9, "IX"},   
        {5, "V"},   
        {4, "IV"},  
        {1, "I"}
    };

    std::string res;
    for (auto [val, ch] : dictionary) {
      while ((num - val) >= 0) {
        // std::cout << num << " - " << val << " = ";
        num -= val;
        // std::cout << num << " += " << ch << std::endl;
        res += ch;
      }
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_INTEGER_TO_ROMAN_H
