#include "Dice.h"
    
std::uint_fast64_t Dice::roll(std::uint_fast64_t n, std::uint_fast64_t d) {
    std::uniform_int_distribution<std::uint_fast64_t> distribution(1,d);
    std::uint_fast64_t roll = 0;
    if (n == 1) {
        roll = distribution(rng);
    }
    else {
        std::uint_fast64_t total = 0;
        for (std::uint_fast64_t i = 0; i < n ; i++) {
            std::uint_fast64_t current_roll = distribution(rng);
            if (current_roll )
            total += distribution(rng);
            roll = total;
        }
    }
    return roll;
}   
