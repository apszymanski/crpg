#ifndef __DICE_H_INCLUDED__
#define __DICE_H_INCLUDED__

#include <random>

class Dice {
    private:
        std::random_device rng{};
    public:
        int roll(int n = 1, int d = 20);
};

#endif /* __DICE_H_INCLUDED__ */
