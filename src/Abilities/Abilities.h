#ifndef __ABILITIES_H_INCLUDED__
#define __ABILITIES_H_INCLUDED__



#endif /* __ABILITIES_H_INCLUDED__ */

/*
#ifndef ABILITIES_H_
#define ABILITIES_H_

#include <array>
#include <string>
#include <iostream>

class Abilities {
    private:
    
        static const std::uint8_t size = 6;
        std::array<std::string, size> ability_names; 
        mutable std::array<std::uint8_t, size> ability_scores;

    public:
    
        // constructors
        Abilities() {
            ability_names = {"STR", "DEX", "CON", "INT", "WIS", "CHA"};
        };
        Abilities(std::array<std::uint8_t, size>);
        Abilities(std::uint8_t);
        
        // deconstructor
        ~Abilities();

        // get and set methods
        std::uint8_t get_ability(std::uint8_t score_index) {
            if (score_index < size) return ability_scores[score_index]; else return -1;
        }

        void set_ability(std::uint8_t score_index, std::uint8_t value) {
            if (score_index < size) ability_scores[score_index] = value;
        }

        // get total of ability scores
        std::uint8_t get_total() {
            std::uint8_t sum;
            for (std::uint8_t i = 0; i < size; i++) {
                sum += ability_scores[i];
            }
            return sum;
        }

        // print ability scores
        void print_ability_score(bool total_flag) {
            for (std::uint8_t i = 0; i < size; i++) {
                std::cout << ability_names[i] << ":\t" << ability_scores[i] << '\n'; 
            }
            std::cout << (total_flag ? std::to_string(get_total()) : "") << std::endl;
        };
};

#endif
*/
