template <int n>
struct is_zero {
    static constexpr bool value = false;
};

template <>
struct is_zero<0> {
    static constexpr bool value = true;
};
