#ifndef SAMPLE_DLL_H
#define SAMPLE_DLL_H
#define EXPORT extern "C" __declspec(dllexport)

EXPORT long long getMicrosecondsInOneTick();

#endif  // SAMPLE_DLL_H