#ifndef SAMPLE_NON_OBVIOUS_NUMS_H
#define SAMPLE_NON_OBVIOUS_NUMS_H
#include <numeric>
#include <vector>

#include "util/log.h"

void test1() {
  // 1.
  float fst = 0.2;
  if (fst != 0.2) util::debug("fst is float, but '0.2' is double\n");
}

void test2() {
  std::vector<float> floats(100);
  for (int i = 0; i < floats.size(); ++i) floats[i] = 1.f / (i + 1);
  float sum1 = std::accumulate(floats.begin(), floats.end(), 0.f);
  float sum2 = std::accumulate(floats.rbegin(), floats.rend(), 0.f);
  std::cout << (sum1 - sum2) << std::endl;
}

void test3() {
  uint64_t x = 10;
  int y = -1;
  if (x < y)
    util::debug("there is an implicit cast y ({}) to unsigned int {}\n", y,
                static_cast<uint64_t>(y));
}
#endif  // SAMPLE_NON_OBVIOUS_NUMS_H