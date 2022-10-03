#include <cstddef>
#ifndef EXAMPLEPROJECT_REF_ANNOTATION_H
#define EXAMPLEPROJECT_REF_ANNOTATION_H

namespace myref {

template <typename T>
class Dummy final {
 public:
  Dummy() : value_() { std::cout << "dummy empty ctor " << this << std::endl; }

  Dummy(const T& value) : value_(value) {
    std::cout << "dummy ctor " << this << std::endl;
  }

  Dummy(Dummy& data) : Dummy(data.value_) {
    std::cout << "dummy copy ctor " << this << std::endl;
  }
  Dummy(Dummy&& data) : Dummy(std::move(data.value_)) {
    std::cout << "dummy move ctor " << this << std::endl;
  }

  Dummy operator=(const Dummy& data) {
    std::cout << "dummy operator=" << this << std::endl;
    return data;
  }
  ~Dummy() { std::cout << "dummy dtor " << this << std::endl; }

  T value() const { return value_; }

 private:
  T value_;
};

class Data final {
 public:
  using DataType = Dummy<int>;

  Data() : value_(Dummy(1024)) { std::cout << "ctor " << this << std::endl; }

  Data(Data& data) : Data() { std::cout << "copy ctor " << this << std::endl; }

  Data(Data&& data) : Data() { std::cout << "move ctor " << this << std::endl; }

  // DataType data() { return value_; }

  // DataType& data() & { return value_; }

  DataType&& data() && { return std::move(value_); }

 private:
  DataType value_;
};

Data newData() { return Data(); }

}  // namespace myref

#endif  // EXAMPLEPROJECT_REF_ANNOTATION_H