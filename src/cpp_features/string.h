#ifndef CPP_FEATURES_STRING_H
#define CPP_FEATURES_STRING_H

#include <cstring>
#include <format>
#include <vector>

#include "../util/log.h"

namespace str {

class String final {
  char* data_;
  size_t size_;
  size_t capacity_;

  const static char sentinel = '\0';

 public:
  // ctor
  String(const char* src) {
    util::debug("ctor\n");
    size_ = std::strlen(src);
    capacity_ = size_ * 2;
    data_ = new char[size_ + 1]{sentinel};
    std::strcpy(data_, src);
  };

  // copy ctor
  String(const String& other) {
    util::debug("copy ctor\n");
    size_ = std::strlen(other.data_);
    capacity_ = size_ * 2;
    data_ = new char[size_ + 1]{sentinel};
    std::strcpy(data_, other.data_);
  }

  // copy assignment
  String& operator=(const String& other) {
    util::debug("copy assignment\n");
    if (this == &other) return *this;

    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new char[size_ + 1]{sentinel};
    std::strcpy(data_, other.data_);
    return *this;
  }

  // move ctor
  String(String&& other) noexcept
      : data_(std::exchange(other.data_, nullptr)),  //
        size_(std::exchange(other.size_, 0)),
        capacity_(std::exchange(other.capacity_, 0)) {
    util::debug("move ctor\n");
  }

  // move assignment
  String& operator=(String&& other) noexcept {
    util::debug("move assignment\n");
    if (this == &other) return *this;

    size_ = std::exchange(other.size_, 0);
    capacity_ = std::exchange(other.capacity_, 0);
    data_ = std::exchange(other.data_, nullptr);

    return *this;
  }

  // dtor
  ~String() {
    util::debug("dtor\n");
    delete[] data_;
  };

  std::string_view toString() const noexcept { return data_; }

  void change1stLetter(const char new_letter) noexcept { data_[0] = new_letter; }
};

void moveSemanthic(str::String str) { util::debug("received str: {}\n", str); }

void sample() {
  String str = "123456789";
  moveSemanthic(std::move(str));

  std::vector<str::String> vec;
  int n = 10;
  vec.reserve(n);
  for (int i = 0; i < n; ++i) {
    vec.push_back({std::format("{}", i).c_str()});
  }

  for (const auto& it : vec) {
    util::debug("[main]:... str = {}\n", it);
  }
}
}  // namespace str

template <>
struct std::formatter<str::String> {
  constexpr auto parse(std::format_parse_context& ctx) { return ctx.begin(); }

  auto format(const str::String& obj, std::format_context& ctx) {
    return std::format_to(ctx.out(), "\"{}\"", obj.toString());
  }
};

#endif  // CPP_FEATURES_STRING_H