#ifndef __ABILITIES_H_INCLUDED__
#define __ABILITIES_H_INCLUDED__

#include <array>
#include <iostream>

enum Ability : int {STR = 0, DEX, CON, INT, WIS, CHA};

class Ability_Array {

        private:
            static const std::size_t size {6};                                  // size should be length of enum
            std::array<int, std::size_t(size)> array{};

        public:
            Ability_Array();
            Ability_Array(int scores[6]);
            int get_score(Ability ability);
            void set_score(Ability ability, int score);
            void print_ability_array();
};

class Abilities {

    private:
        /* Array containing ability score information.
         * The first Ability_Array contains the raw scores,
         * the second total abilities including any modifiers (race, ASI, equipment),
         * and the third contains the ability score modifiers.
         */
        std::array<Ability_Array, std::size_t(3)> abilities{};

    public:
        Abilities();
        Abilities(std::array<Ability_Array, std::size_t(3)> array);

        int get_base_ability_score(Ability ability);
        void set_base_ability_score(Ability ability, int score);
        Ability_Array get_all_base_ability_scores();

        int get_total_ability_score(Ability ability);
        void set_total_ability_score(Ability ability, int score);
        Ability_Array get_all_total_ability_scores();

        int get_ability_modifier(Ability ability);
        void set_ability_modifier(Ability ability, int modifier);
        Ability_Array get_all_ability_modifiers();

        void print_abilities();
 
};

#endif /* __ABILITIES_H_INCLUDED__ */
