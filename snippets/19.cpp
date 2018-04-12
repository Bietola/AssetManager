template <class T, T v>
struct integral_constant {
    static constexpr T value = v;
    constexpr operator T() const noexcept {return value;}
    // other useful stuff...
};
