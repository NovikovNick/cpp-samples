#define DEBUG 1;

#include "util/log.h"
#include <sample_dll.h>

int main(int argc, char argv[]) {
  util::debug("Sample dll {}\n", getMicrosecondsInOneTick());
  return 0;
}
