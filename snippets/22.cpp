template <int n>
struct is_zero : std::false_type {};

template <>
struct is_zero<0> : std::true_type {};
