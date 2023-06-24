#include "sample_dll.h"

Platform evalOperation(const Location& location, Operation operation) {
  Platform res = {};
  switch (operation) {
    case Operation::PLUS: {
      for (int i = 0; i < location.platforms_count; ++i)
        res.id += location.platforms[i].id;
      break;
    }

    case Operation::MINUS: {
      for (int i = 0; i < location.platforms_count; ++i)
        res.id -= location.platforms[i].id;
      break;
    }
  }
  return res;
}

long long getMicrosecondsInOneTick() { return 42; }