template <class T>
void check(const T& t, const T& s) {
    if(t.size() < 10 && s.getFlag() == T::OK)
        std::cout << "ok\n";
}
