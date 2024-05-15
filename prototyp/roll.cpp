#include "util.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <random>
using namespace std;

/*
    rolls character abilities for a new character
    using psudo-random numbers, checks against total 72
    and prints result to screen
*/

/* old roll with rand with srand(time(NULL)); in main
int roll_d(uint d) {
    int roll = 1 + ((int) (10.0 * (rand() / (RAND_MAX + 1.0))) % d);
    return roll;
}
*/
// rolls d(int d)
int roll_d(uint d) {
    random_device source;
    uniform_int_distribution<int> distribution(1,d);
    int roll = distribution(source);
    return roll; 
}

// rolls for single ability (4d6 - worst) and returns the score
int roll_ability() {
    // initialize roll array
    int rolls[4] = {roll_d(6), roll_d(6), roll_d(6), roll_d(6)};

    // search for lowest roll and set to 0
    int min_index_rolls = int_array_min_index(rolls, (int)(sizeof rolls / sizeof rolls[0]));
    rolls[min_index_rolls] = 0;
    
    // calculates and returns ability from roll
    int ability_score = int_array_sum(rolls, (int)(sizeof rolls / sizeof rolls[0]));
    return ability_score;
}

int main() {
        
    // array ability names
    string ability_names[6] = {"STR", "DEX", "CON", "INT", "WIS", "CHA"};

    // array of ability scores
    int ability_scores[6];

    for (int i = 0; i < 6; i++) {
        ability_scores[i] = roll_ability();
    }
    
    // print ability names and respective scores
    print_ability_score(ability_names, ability_scores, 6, true);

    return 0;
}
