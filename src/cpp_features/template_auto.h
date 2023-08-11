namespace templates {

template <auto Val>
struct intergral_constant {
  using value_type = decltype(Val);
  static constexpr value_type value = Val;
};

using six_type = intergral_constant<6>;
using one_type = intergral_constant<1>;

}  // namespace templates