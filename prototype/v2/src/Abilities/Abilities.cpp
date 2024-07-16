#include "Abilities.h"

Ability_Array::Ability_Array()
{
    array = {0, 0 ,0 ,0 ,0 ,0};
}

Ability_Array::Ability_Array(int scores[])
{
    for (std::size_t i = 0; i < array.max_size(); i++)
    array[i] = scores[i];
}

int Ability_Array::get_array_size()
{
    return int (size);
}

std::string Ability_Array::get_ability_identifier(Ability ability)
{
    return identifiers[ability];
}

int Ability_Array::get_score(Ability ability)
{
    return array[ability];
}

void Ability_Array::set_score(Ability ability, int score)
{
    array[ability] = score;
}

void Ability_Array::print_identifiers()
{
    for (std::size_t i {}; i < size; ++i){
        std::cout << '\t' << get_ability_identifier(Ability (i));
    }
    std::cout << '\n';
}

void Ability_Array::print(bool sign = false)
{
    std::cout << '\t';
    for (std::size_t i = 0; i < size; i++) {
        if (sign) {
            std::cout << (array[i] > 0 ? "+" : "") << array[i] << '\t';
        } else {
            std::cout << array[i] << '\t';
        }
    }
    std::cout << '\n';
}

Ability_Change::Ability_Change()
{

}

Ability_Change::Ability_Change(Ability ability_score, int score_change, std::string change_source)
{
    ability = ability_score;
    change = score_change;
    source.append(change_source);
}

Ability Ability_Change::get_ability()
{
    return ability;
}

int Ability_Change::get_change()
{
    return change;
}

std::string Ability_Change::get_source()
{
    return source;
}

Abilities::Abilities()
{ 
    base = Ability_Array();
    total = Ability_Array();
    modifiers = Ability_Array();
}

Abilities::Abilities(int array[6])
{
    base = Ability_Array(array);
    total = Ability_Array(array);
    update_all_modifiers();
}

Abilities::Abilities(std::array<Ability_Array, std::size_t(3)> array)
{
    base = array.at(0);
    total = array.at(1);
    modifiers = array.at(2);
}

int Abilities::get_base_score(Ability ability)
{
    return base.get_score(ability);
}

Ability_Array Abilities::get_all_base_scores()
{
    return base;
}

void Abilities::set_base_score(Ability ability, int score)
{
    base.set_score(ability, score);
}

int Abilities::get_total_score(Ability ability)
{
    return total.get_score(ability);
}

Ability_Array Abilities::get_all_total_scores()
{
    return total;
}

void Abilities::set_total_score(Ability ability, int score)
{
    total.set_score(ability, score);
}

int Abilities::get_modifier(Ability ability)
{
    return modifiers.get_score(ability);
}

Ability_Array Abilities::get_all_modifiers()
{
    return modifiers;
}

void Abilities::set_modifier(Ability ability, int score)
{
    modifiers.set_score(ability, score);
}

void Abilities::update_all_modifiers()
{
    for (int i {}; i < modifiers.get_array_size(); ++i) {
        Ability ability = Ability (i);
        int current_score = get_total_score(ability);
        if (current_score < 2) {
            set_modifier(ability, -5);
        } else if (current_score < 4) {
            set_modifier(ability, -4);
        } else if (current_score < 6) {
            set_modifier(ability, -3);
        } else if (current_score < 8) {
            set_modifier(ability, -2);
        } else if (current_score < 10) {
            set_modifier(ability, -1);
        } else if (current_score < 12) {
            set_modifier(ability, 0);
        } else if (current_score < 14) {
            set_modifier(ability, 1);
        } else if (current_score < 16) {
            set_modifier(ability, 2);
        } else if (current_score < 18) {
            set_modifier(ability, 3);
        } else if (current_score < 20) {
            set_modifier(ability, 4);
        } else if (current_score < 22) {
            set_modifier(ability, 5);
        } else if (current_score < 24) {
            set_modifier(ability, 6);
        } else if (current_score < 26) {
            set_modifier(ability, 7);
        } else if (current_score < 28) {
            set_modifier(ability, 8);
        } else {
            set_modifier(ability, 10);
        }
    }
}

// TODO figure out history

void Abilities::update_abilities(Ability_Change change)
{
    history.push_back(change);
    Ability changed_ability = change.get_ability();
    int current_score = get_total_score(changed_ability);
    int score_modification = change.get_change();
    int new_score = current_score + score_modification;
    set_total_score(changed_ability, new_score);
    update_all_modifiers();
}

void Abilities::print()
{   base.print_identifiers();
    std::cout << "Base:" << '\n';
    base.print();
    std::cout << "Total:" << '\n';
    total.print();
    std::cout << "Modifiers:" << '\n';
    modifiers.print(true);
}
