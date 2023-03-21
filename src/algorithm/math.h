#ifndef SAMPLE_NON_OBVIOUS_NUMS_H
#define SAMPLE_NON_OBVIOUS_NUMS_H

#include "util/log.h"

void factorize(int x) {
  int divisor = 2;
  while (x != 1) {
    if (x % divisor == 0) {
      util::debug("{}\n", divisor);
      x /= divisor;
    } else {
      ++divisor;
    }
  }
}

#endif  // SAMPLE_NON_OBVIOUS_NUMS_H