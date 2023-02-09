#include <string>;

#include "../util/log.h"

/*
convert num to base string
*/
std::string toBaseString(uint32_t num, const uint8_t base) {
  std::string res;
  while (num != 0) {
    util::debug("{:10d} % {:2d} = {}\n", num, base, num % base);
    res.append(std::to_string(num % base));
    num /= base;  // num >>= 1;
  }
  std::reverse(res.begin(), res.end());
  return res;
}

int hammingWeight(uint32_t n) {
  int ans = 0;
  for (int i = 0; i < 32; i++) {
    if (n & (1 << i)) ans++;
  }
  return ans;
}

uint64_t convert(const uint32_t lhs, const uint32_t rhs) {
  return (static_cast<uint64_t>(lhs) << 32) | (rhs & 0xffffffffL);
}

std::pair<uint32_t, uint32_t> convert(const uint64_t val) {
  return {val >> 32, val};
}