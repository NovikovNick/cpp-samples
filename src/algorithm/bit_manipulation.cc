#include "../util/log.h"
#include <string>;

/*
convert num to base string
*/
std::string toBaseString(uint32_t num, const uint8_t base) {
  std::string res;
  while (num != 0) {
    util::debug("{:10d} % {:2d} = {}\n", num, base, num % base);
    res.append(std::to_string(num % base));
    num /= base; // num >>= 1;
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