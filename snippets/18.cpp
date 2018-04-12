template <class T, class = void>
struct is_asset : std::false_type {};

template <class T>
struct is_asset<T,
    std::void_t<decltype(
        std::declval<T>().loadFromFile(std::declval<const char*>())
    )>
> : std::true_type {};
