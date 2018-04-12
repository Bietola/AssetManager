#include <iostream>

template <template <class> class F, class T>
struct call {
    using type = void;
};

template <template <class> class F, class T> 
struct call<F, T> {
    using type = typename F<T>::type;
};

template <class T>
struct identity {
    using type = T;
};

int main() {
    typename call<identity, int>::type x = 10;

    std::cout << "x is an int of value " << x << std::endl;

    return 0;
}
