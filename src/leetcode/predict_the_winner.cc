#ifndef LEETCODE_PREDICT_THE_WINNER_H
#define LEETCODE_PREDICT_THE_WINNER_H
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

class Solution {
 public:
  bool PredictTheWinner(vector<int>& nums) {
    return turnPlayer1st(nums, 0, nums.size() - 1, 0, 0);
  }

  bool turnPlayer1st(const std::vector<int>& nums,
                     const int left_index,
                     const int right_index,
                     const int player_1st_score,
                     const int player_2nd_score) {
    if (right_index == left_index) {
      return player_1st_score + nums[left_index] >= player_2nd_score;
    }
    return turnPlayer2nd(nums,
                         left_index + 1,
                         right_index,
                         player_1st_score + nums[left_index],
                         player_2nd_score)  //
           ||                               //
           turnPlayer2nd(nums,
                         left_index,
                         right_index - 1,
                         player_1st_score + nums[right_index],
                         player_2nd_score);
  }

  bool turnPlayer2nd(const std::vector<int>& nums,
                     const int left_index,
                     const int right_index,
                     const int player_1st_score,
                     const int player_2nd_score) {
    if (right_index == left_index) {
      return player_1st_score >= player_2nd_score + nums[left_index];
    }
    return turnPlayer1st(nums,
                         left_index + 1,
                         right_index,
                         player_1st_score,
                         player_2nd_score + nums[left_index])  //
           &&                                                  //
           turnPlayer1st(nums,
                         left_index,
                         right_index - 1,
                         player_1st_score,
                         player_2nd_score + nums[right_index]);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_PREDICT_THE_WINNER_H
