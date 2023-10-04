#ifndef CPP_FEATURES_CRTP_H
#define CPP_FEATURES_CRTP_H

#include "../util/log.h"

namespace crtp {

/* Simple CRTP */

template <typename T>
class Base {
 public:
  void setData(int data) { static_cast<T*>(this)->setDerivedData(data); }
  void printData() const { static_cast<const T*>(this)->printDerivedData(); }
};

class Derived1 : public Base<Derived1> {
  int data_;

 public:
  Derived1(const int data) : data_(data){};
  void setDerivedData(const int val) { data_ = val; };
  void printDerivedData() const {
    util::debug("[crtp, 1st derived]:... {}\n", data_);
  };
};

class Derived2 : public Base<Derived2> {
  int data_;

 public:
  Derived2(const int data) : data_(data){};
  void setDerivedData(const int val) { data_ = val * 2; };
  void printDerivedData() const {
    util::debug("[crtp, 2nd derived]:... {}\n", data_);
  };
};

template <typename Arg>
void staticPolymorphicHandler(Arg arg, const int data) {
  arg.setData(data);
  arg.printData();
}

/* Mixin */

template <typename T>
struct MyCounter {
  MyCounter() { ++count_; }
  ~MyCounter() { --count_; }
  int count() const { return count_; }

 private:
  inline static int count_ = 0;
};

struct A : MyCounter<A> {};

/* SAMPLE #1 */

template <class ValueT>
struct Filter {
  virtual bool check(const ValueT& value) const = 0;
};

template <class ValueT, class CandidateT, class DerivedT>
struct Functional : public Filter<ValueT> {
  typedef std::function<bool(const CandidateT&)> Check;

  Functional(Check check) : m_check(check){};

  bool check(const ValueT& value) const override {
    const auto& candidate = DerivedT::_extract(value);
    return bool(candidate) && m_check(*candidate);
  }

 private:
  Check m_check;
};

struct Test {
  int value;
};

struct Equal : Functional<Test, int, Equal> {
  Equal(const int value)
      : Functional([target = value](const int value) { return target == value; }){};

  static const int* _extract(const Test& value) { return &value.value; }
};

void sample() {
  /*simple crtp */
  // staticPolymorphicHandler(Derived1{1}, 2);
  // staticPolymorphicHandler(Derived2{1}, 2);

  /* mixin sample */
  /*A a1;
  util::debug("count: {}\n", a1.count());
  A a2, a3, a4;
  util::debug("count: {}\n", a1.count());
  {
    A a5, a6, a7;
    util::debug("count: {}\n", a1.count());
  }
  util::debug("count: {}\n", a1.count());*/

  Filter<Test>* filter = new Equal(5);
  filter->check(Test{4});
}
}  // namespace crtp

#endif  // CPP_FEATURES_CRTP_H