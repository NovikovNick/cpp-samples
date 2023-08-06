#ifndef LEETCODE_NUMBER_OF_MUSIC_PLAYLISTS_H
#define LEETCODE_NUMBER_OF_MUSIC_PLAYLISTS_H
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
  int numMusicPlaylists(int n, int goal, int k) {
    debug("music playlist\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_NUMBER_OF_MUSIC_PLAYLISTS_H
