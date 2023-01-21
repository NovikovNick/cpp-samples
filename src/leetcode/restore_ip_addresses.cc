#ifndef LEETCODE_RESTORE_IP_ADDRESSES_H
#define LEETCODE_RESTORE_IP_ADDRESSES_H
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
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  vector<string> restoreIpAddresses(string s) {
    std::vector<std::string> res;
    std::vector<uint8_t> ip;
    backtracking(0, ip, s, res);
    return res;
  }

  void backtracking(int s_index, std::vector<uint8_t>& ip, std::string& s,
                    std::vector<std::string>& res) {
    if (!ip.empty()) {
      for (int i = 0; i < (ip.size() - 1); ++i) debug("{:3d}.", ip[i]);
      debug("{:3d}\n", ip[ip.size() - 1]);
    }

    int n = s.size();
    if (s_index == n || ip.size() == 4) {
      if (s_index == n && ip.size() == 4) {
        std::string ip_str = std::to_string(ip[0]);
        for (int i = 1; i < 4; ++i)
          ip_str.append(".").append(std::to_string(ip[i]));
        res.push_back(ip_str);
      }
      return;
    };

    if (s[s_index] == '0') {
      ip.push_back(0);
      backtracking(s_index + 1, ip, s, res);
      ip.pop_back();
    } else {
      auto num = std::to_string(s[s_index] - '0');
      while (std::stoi(num) <= 255 && s_index < n) {
        if ((n - s_index - 1) <= (4 - ip.size() - 1) * 3) {
          ip.push_back(std::stoi(num));
          backtracking(s_index + 1, ip, s, res);
          ip.pop_back();
        }
        ++s_index;
        num.append(std::to_string(s[s_index] - '0'));
      }
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_RESTORE_IP_ADDRESSES_H
