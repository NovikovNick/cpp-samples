#ifndef SAMPLE_DLL_H
#define SAMPLE_DLL_H
#define EXPORT extern "C" __declspec(dllexport)

enum Operation {
  PLUS = 0,
  MINUS = 1
};

struct Platform {
  int id, type, width, height;
};

struct Location {
  bool is_1st_player;
  Platform* platforms;
  unsigned long long platforms_count;
};

EXPORT Platform evalOperation(const Location& location, Operation operation);

EXPORT long long getMicrosecondsInOneTick();

#endif  // SAMPLE_DLL_H