#ifndef __ABILITIES_H_INCLUDED__
#define __ABILITIES_H_INCLUDED__

#include <array>
#include <vector>
#include <iostream>

// maps Ability Attributes to int for indexing
enum Ability : int {STR = 0, DEX, CON, INT, WIS, CHA};

class Ability_Array {

    private:
        static const std::size_t size {6};                                      // size should be length of enum
        std::array<int, std::size_t(size)> array {};

    public:
        Ability_Array();
        Ability_Array(int[size]);
        static int get_array_size();
        int get_score(Ability);
        void set_score(Ability,int);
        void print_ability_array(bool);
};

class Ability_Change {
    private:
        Ability ability {};
        int change {};
        std::string source {};
    public:
        Ability_Change();
        Ability_Change(Ability, int, std::string);
        
        Ability get_ability();
        int get_change();
        std::string get_source();
};

class Abilities {

    private:
        Ability_Array base {};
        Ability_Array total {};
        Ability_Array modifiers {};
        std::vector<Ability_Change> history {};

    public:
        Abilities();
        Abilities(int[6]);
        Abilities(std::array<Ability_Array, std::size_t(3)>);

        int get_base_score(Ability);
        Ability_Array get_all_base_scores();
        void set_base_score(Ability, int);

        int get_total_score(Ability);
        Ability_Array get_all_total_scores();
        void set_total_score(Ability, int);

        int get_modifier(Ability);
        Ability_Array get_all_modifiers();
        void set_modifier(Ability, int);
        void update_all_modifiers();

        //TODO figure out history

        void update_abilities(Ability_Change);

        void print_abilities();
};

#endif /* __ABILITIES_H_INCLUDED__ */
