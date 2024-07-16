#ifndef __ABILITIES_HPP_INCLUDED__
#define __ABILITIES_HPP_INCLUDED__

#include <array>
#include <vector>
#include <iostream>

// map abilty attributes to int for indexing
enum Ability : int {STR = 0, DEX, CON, INT, WIS, CHA};

class Ability_Array {

    private:
        static const std::size_t size {6};                                      // size should be length of enum
        std::array<std::string, std::size_t(size)> identifiers {"STR", "DEX", "CON", "INT", "WIS", "CHA"};
        std::array<int, std::size_t(size)> array {};

    public:
        Ability_Array();
        Ability_Array(int[size]);

        static int get_array_size();
        std::string get_ability_identifier(Ability);

        int get_score(Ability);
        void set_score(Ability,int);
        void print_identifiers();
        void print(bool);
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

        // manipulating base
        int get_base_score(Ability);
        Ability_Array get_all_base_scores();
        void set_base_score(Ability, int);

        // manipulating total
        int get_total_score(Ability);
        Ability_Array get_all_total_scores();
        void set_total_score(Ability, int);

        // manipulating modifier
        int get_modifier(Ability);
        Ability_Array get_all_modifiers();
        void set_modifier(Ability, int);
        void update_all_modifiers();

        //TODO figure out history

        void update_abilities(Ability_Change);

        void print();
};

#endif /* __ABILITIES_HPP_INCLUDED__ */
