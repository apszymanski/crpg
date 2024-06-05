#include "Dice.h"
#include <iostream>
#include <array>

void get_random_numbers(Dice* die_ptr) {
    for (std::uint_fast64_t i = 0; i < 10; i++) {
        std::uint_fast64_t number = die_ptr->roll();
        std::cout << number << '\n';
    }
}

void check_distribution(Dice* die_ptr, std::uint_fast64_t n = 1000) {
    std::array<std::uint_fast64_t, 20> count{}; 

    for (std::uint_fast64_t i = 0; i < n; i++) {
        std::uint_fast64_t current_roll = die_ptr->roll();
        count[current_roll - 1]++;
    }

    for (std::uint_fast64_t i = 0; i < 20; i++) {
        std::cout << std::to_string(i + 1) << ":\t" << std::string(count[i] / 10, '*') << '\t' << '\n';
    }
}

int main() {
    Dice die = Dice();
    
    for (std::uint_fast64_t i {}; i < 5; i++) {
        std::cout << die.roll() << std::endl;
    }
    
    std::cout << die.roll() << std::endl;
    Dice* dice_ptr = &die;
    check_distribution(dice_ptr, 10000);
}
