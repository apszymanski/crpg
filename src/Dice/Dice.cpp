#include "Dice.h"
    
std::uint64_t Dice::roll(std::uint64_t n, std::uint64_t d) {
    std::uniform_int_distribution<> distribution(1,d);
    std::uint64_t roll = 0;
    if (n == 1) {
        roll = distribution(rng);
    }
    else {
        std::uint64_t total = 0;
        for (std::uint64_t i = 0; i < n ; i++) {
            total += distribution(rng);
            roll = total;
        }
    }
    return roll;
}   