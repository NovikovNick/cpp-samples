#ifndef CPP_FEATURES_CONCEPTS_H
#define CPP_FEATURES_CONCEPTS_H

#include "../util/log.h"

/// <summary>
/// https://en.cppreference.com/w/cpp/language/constraints
/// </summary>
namespace concepts {

template <typename T>
concept Iterable = requires(T t) {
                     { ++t } -> std::same_as<T&>;
                     { t++ } -> std::same_as<T>;
                   };

template <typename T>
concept Hashable = requires(T a) {
                     { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
                   };

template <typename T>
concept Prinable = requires(T t) {
                     { t.print() };
                   };

template <typename T>
concept MyType = requires(T t) {
                   requires Iterable<T>;
                   // requires Hashable<T>;
                   requires Prinable<T>;
                 };

struct A {
  A(){};

  A(const A&){};

  A& operator++() { return *this; }
  A operator++(int) { return *this; }

  void print(){};
};

// 1
template <MyType T> 
void foo([[maybe_unused]] T t) {}
// 2
void foo2([[maybe_unused]] MyType auto t) {}
// 3
template <class T> requires Iterable<T> && Prinable<T>
void bar([[maybe_unused]] T t) {}


void sample() {
  util::debug(" === Concepts === \n");
  A a{};
  foo(a);
  foo2(a);
  bar(a);
}

}  // namespace concepts

#endif  // CPP_FEATURES_CONCEPTS_H