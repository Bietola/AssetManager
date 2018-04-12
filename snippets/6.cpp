template <class Animal>
std::string makeSound(const Animal& animal) {
    return animal.makeSound();
}

struct Dog {
    std::string makeSound() const {
        return "more bark!!!";
    }
};

struct Cat {
    std::string makeSound() const {
        return "still meowing...";
    }
};
