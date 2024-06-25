#include "Dice.h"

#include <array>
#include <string>
#include <iostream>
#include <random>

void get_random_numbers(Dice *ptr, int n = 10)
{
    for (int i {}; i < n; ++i){
        std::cout << ptr->roll() << "\n";
    }
}

void check_distribution(Dice *ptr, int n = 10000)
{   
    std::array<int, 20> counter{};
    for (int i {}; i < n; ++i) {
        int current_roll {ptr->roll()};
        ++counter.at(std::size_t (current_roll - 1));
    }

    for (int i {}; i < 20; ++i) {
        std::cout << i + 1 << ": \t" << std::string(std::size_t (counter.at(std::size_t (i))) / 10, '*') << '\n';
    }
}

int main()
{
    Dice die = Dice();
    Dice *dice_ptr = &die;
    get_random_numbers(dice_ptr);
    check_distribution(dice_ptr);
}
