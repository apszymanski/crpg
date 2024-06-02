#ifndef __DICE_H_INCLUDED__
#define __DICE_H_INCLUDED__

#include <cstddef>
// for random number generation
#include <random>

class Dice {
private:
    std::random_device rng;
public:
    std::uint64_t roll(std::uint64_t n = 1, std::uint64_t d = 20);
};

#endif /* __DICE_H_INCLUDED__ */
