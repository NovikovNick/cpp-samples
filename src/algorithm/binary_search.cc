#include "../util/log.h"

int lowerBound(std::vector<int>& arr, int val) {
  int low = 0, mid, high = arr.size() - 1;
  util::debug(" low  mid high\n");
  while (low <= high) {
    mid = low + (high - low) / 2;
    util::debug("{:4d} {:4d} {:4d} ", low, mid, high);
    if (arr[mid] >= val) {
      util::debug(" left\n");
      high = mid - 1;
    } else {
      util::debug(" right\n");
      low = mid + 1;
    }
  }
  return low;
};

int upperBound(std::vector<int>& arr, int val) {
  int low = 0, mid, high = arr.size() - 1;
  util::debug(" low  mid high\n");
  while (low <= high) {
    mid = low + (high - low) / 2;
    util::debug("{:4d} {:4d} {:4d} ", low, mid, high);
    if (arr[mid] > val) {
      high = mid - 1;
      util::debug(" left\n");
    } else {
      util::debug(" right\n");
      low = mid + 1;
    }
  }
  return low;
};
