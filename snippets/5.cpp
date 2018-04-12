struct Animal {
    virtual std::string makeSound() const = 0;
};

struct Dog : public Animal {
    std::string makeSound() const override {
        return "barking!!";
    }
};

struct Cat : public Animal {
    std::string makeSound() const override {
        return "meowing...";
    }
};
