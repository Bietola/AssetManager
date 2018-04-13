#include <iostream>

template <size_t num>
struct is_zero : std::false_type {};

template <>
struct is_zero<0> : std::true_type {};

template <size_t num>
bool is_zero_v = is_zero<num>::value;

int main() {
    std::cout << std::boolalpha << is_zero_v<1> << std::endl;

    return 0;
}
