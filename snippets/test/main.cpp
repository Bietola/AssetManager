#include <type_traits>

template <int num>
struct plus_one :
    std::integral_constant<int, num + 1> {};

int main() {
    std::cout << plus_one<1>::value << std::endl;

    return 0;
}
