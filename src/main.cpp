#include "cpp_features/common.h"
#include "util/log.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char argv[]) {
  const int& const a = 1;

  
  util::debug("{}", argc);
  return 0;
}
