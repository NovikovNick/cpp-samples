#include <iostream>

void test() {
  // 1.
  float fst = 0.2;
  if (fst != 0.2) std::cout << "fst is float, but '0.2' is double\n";

  // 2.
  std::vector<float> floats(100);
  for (int i = 0; i < floats.size(); ++i) floats[i] = 1.f / (i + 1);
  float sum1 = std::accumulate(floats.begin(), floats.end(), 0.f);
  float sum2 = std::accumulate(floats.rbegin(), floats.rend(), 0.f);
  std::cout << (sum1 - sum2) << std::endl;
}