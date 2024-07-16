#include "dice.hpp"

int Dice::roll(int n = 1, int d = 20)
{
    int roll{};

    if (d == 2) {
        std::uniform_int_distribution<int> distribution(0,1);

        if (n == 1) {
            roll = distribution(rng);

        } else {
            int total {};
            for (int i {}; i < n; ++i) {
                total += distribution(rng);
            }
            roll = total;
        }
    } else {
        std::uniform_int_distribution<int> distribution(1,d);

        if (n == 1) {
            roll = distribution(rng);
        } else {
            int total {};
            for (int i {}; i < n; ++i) {
                total += distribution(rng);
            }
            roll = total;
        }
    }
    return roll;
}
