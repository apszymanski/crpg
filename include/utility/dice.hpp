#ifndef __DICE_HPP_INCLUDED__
#define __DICE_HPP_INCLUDED__

#include <random>

class Dice {
    private:
        std::random_device rng{};
    public:
        int roll(int, int);
};

#endif /* __DICE_HPP_INCLUDED__ */
