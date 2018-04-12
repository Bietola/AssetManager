template <int n>
struct plus_one :
    std::integral_constant<int, n + 1> {};
