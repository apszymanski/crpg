#include "Abilities.h"

Ability_Array::Ability_Array() {
    array = {0, 0, 0, 0, 0, 0};
};

Ability_Array::Ability_Array(int scores[]){
    for (std::size_t i = 0; i < array.max_size(); i++)
    array[i] = scores[i];
};

int Ability_Array::get_score(Ability ability) {
    return array[ability];
};

void Ability_Array::set_score(Ability ability, int score) {
    array[ability] = score;
};

void Ability_Array::print_ability_array() {
    std::cout << '\t' << "STR" << '\t' << "DEX" << '\t' << "CON" << '\t'
                      << "INT" << '\t' << "WIS" << '\t' << "CHA" << '\n';
    std::cout << '\t';
    for (std::size_t i = 0; i < size; i++) {
        std::cout << array[i] << '\t';

    }
    std::cout << '\n';

};

Abilities::Abilities() {
    abilities = {Ability_Array(), Ability_Array(), Ability_Array()};
};

Abilities::Abilities(std::array<Ability_Array, std::size_t(3)> array) {
    abilities = array;
};

int Abilities::get_base_ability_score(Ability ability) {
    return abilities[0].get_score(ability);
};

void Abilities::set_base_ability_score(Ability ability, int score) {
    abilities[0].set_score(ability, score);
}

Ability_Array Abilities::get_all_base_ability_scores() {
    return abilities[0];
}

int Abilities::get_total_ability_score(Ability ability) {
    return abilities[1].get_score(ability);
}

void Abilities::set_total_ability_score(Ability ability, int score) {
    abilities[1].set_score(ability, score);
}

Ability_Array Abilities::get_all_total_ability_scores() {
    return abilities[1];
}

int Abilities::get_ability_modifier(Ability ability) {
    return abilities[2].get_score(ability);
}

void Abilities::set_ability_modifier(Ability ability, int score) {
    abilities[2].set_score(ability, score);
}

Ability_Array Abilities::get_all_ability_modifiers() {
    return abilities[2];
}

void Abilities::print_abilities() {
    std::cout << "Base ability scores:" << '\n';
    abilities[0].print_ability_array();
    std::cout << "Total ability scores:" << '\n';
    abilities[1].print_ability_array();
    std::cout << "Ability modifiers:" << '\n';
    abilities[2].print_ability_array();
}
