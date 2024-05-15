#include <random>

class Dice {
    private:
        std::random_device rng;
    public:
        Dice();
        std::int64_t roll() {return rng();}
};

int main() {
    Dice d;
    d.roll();
}