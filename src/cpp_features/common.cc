#include "common.h"


namespace common {

//void A::foo() const { util::debug("[  A  ]:...bar!\n"); };

std::optional<int> toInt(std::string_view str) {
  int num;
  auto [ptr, errc] = std::from_chars(str.data(), str.data() + str.size(), num);
  /*switch (errc) {
    case std::errc::invalid_argument: util::debug("not a number"); break;
    case std::errc::result_out_of_range: util::debug("out of range"); break;
  }*/
  return errc == std::errc{}  //
             ? std::make_optional(num)
             : std::nullopt;
}

void fromCharsSample() {
  for (std::string_view str : {"1234", "15 foo", "bar", " 42", "5000000000"}) {
    auto num = toInt(str);
    // util::debug("{} => {} \n", str, num.has_value() ? num.value() : -1);
    util::debug("{} => {} \n", str, num.value_or(-1));
  }
}

void stringViewSample() {
  std::vector<std::string> arr{"Sunday",  //
                               "Monday",
                               "Tuesday",
                               "Wednesday",
                               "Thirsday",
                               "Friday",
                               "Saturday"};

  auto compareString = [](std::string_view lhs, std::string_view rhs) {
    return lhs.substr(3) < rhs.substr(3);
  };

  std::sort(arr.begin(), arr.end(), compareString);

  for (std::string_view str : arr) util::debug("{}\n", str);
}

void variantSample() {
  struct Visiter {
    void operator()(const A& a) { a.foo(); }
    void operator()(const B& b) { b.bar(); }
  };
  std::vector<std::variant<A, B>> different_objects;

  different_objects.push_back(A{});
  different_objects.push_back(B{});

  for (const auto obj : different_objects) std::visit(Visiter{}, obj);
}

int getCountOneBit(int num) {
  // return std::bitset<32>(num).count();
  int count = 0;
  for (; num != 0; num >>= 1) {
    if (num & 1) ++count;
  }
  return count;
}

void A::foo() const { util::debug("[  A  ]:...foo!\n"); }

void B::bar() const { util::debug("[  B  ]:...bar!\n"); }

}  // namespace common
