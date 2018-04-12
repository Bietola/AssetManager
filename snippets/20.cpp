#include <type_traits>

template <int num>
struct plus_one :
    std::integral_constant<int, num + 1> {};
