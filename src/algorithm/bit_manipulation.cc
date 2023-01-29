#include "../util/log.h"
#include <string>;

/*
convert num to base string
*/
std::string toBaseString(int num, const int base) {
  std::string res;
  while (num != 0) {
    util::debug("{} % {} = {}\n", num, base, num % base);
    res.append(std::to_string(num % base));
    num = num / base;
  }
  std::reverse(res.begin(), res.end());
  return res;
}

int hammingWeight(uint32_t n) {
  int ans = 0;
  for (int i = 0; i < 32; i++) {
    std::cout << std::bitset<32>(1 << i) << std::endl;
    if (n & (1 << i)) ans++;
  }
  return ans;
}