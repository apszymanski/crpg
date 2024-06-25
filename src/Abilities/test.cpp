#include "Abilities.h"

void test_Ability()
{   
    std::cout << "Testing Ability!\n\n";
    std::array<Ability, 6> array {STR, DEX, CON, INT, WIS, CHA};
    for (int i {}; i < 6; ++i) {
        if (array[size_t(i)] == i) {
            std::cout << "OK\n";
        }
    }
    std::cout << "\n\n";
}

void test_Ability_Array()
{
    std::cout << "Testing Ability_Array!\n\n";
    Ability_Array a;
    std::cout << "Ability Array size is: "<< a.get_array_size() << '\n';
    a.print_ability_array(false);
    int b_base[]{1,2,3,4,5,6};
    Ability_Array b(b_base);
    b.print_ability_array(false);
    a.set_score(CHA, 6);
    int a_cha = a.get_score(CHA);
    int b_cha = b.get_score(CHA);
    if (a_cha == b_cha) {
        std::cout << "Success!" << '\n';
    }
    std::cout << "\n\n"; 
}

void test_Ability_Change()
{   
    std::cout << "Testing Ability_Change!\n\n";
    Ability_Change change_plus = Ability_Change(STR, 1, "test_plus");
    Ability_Change change_minus = Ability_Change(INT, -1, "test_minus");
    std::cout << change_plus.get_ability() << 
                 (change_plus.get_change() > 0 ? " +" : " ") <<
                 change_plus.get_change() << " " <<
                 change_plus.get_source() << '\n';

    std::cout << change_minus.get_ability() << 
                 (change_minus.get_change() > 0 ? " +" : " ") <<
                 change_minus.get_change() << " " <<
                 change_minus.get_source() << '\n';
    std::cout << "\n\n";

}

void test_Abilities()
{
    std::cout << "Testing Abilities\n";
    std::cout << "Testing default constructor\n";
    Abilities a;
    std::cout << "Abilities a\n";
    a.print_abilities();
    std::cout << '\n';

    std::cout << "Testing parametrized constructor\n"; 
    int b_base[] {1,2,3,4,5,6};
    int b_total[] {2,3,4,5,6,7};
    int b_modifier[] {0,0,0,0,0,0};
    std::array<Ability_Array, std::size_t(3)> array {Ability_Array(b_base), Ability_Array(b_total), Ability_Array(b_modifier)};
    Abilities b = Abilities(array);
    b.update_all_modifiers();
    std::cout << "Abilities b\n";
    b.print_abilities();
    std::cout << '\n';
    std::cout << "Abilities b after changes:\n";
    b.set_total_score(STR, 12);
    b.update_all_modifiers();
    b.print_abilities();
    std::cout << "\n\n";

    int std_array[6] {15, 14, 13, 12, 10, 8};
    for (int i {}; i < 6; ++i) {
        a.set_base_score(Ability(i), std_array[std::size_t(i)]);
        a.set_total_score(Ability(i), std_array[std::size_t(i)]);
        a.update_all_modifiers();
    }
    std::cout << "Abilities \"a\" after changes:\n";
    a.print_abilities();
    std::cout << "get_base_score(INT): " << a.get_base_score(INT) << '\n';
    std::cout << "get_all_base_scores():\n";
    a.get_all_base_scores().print_ability_array(false);
    std::cout << "get_total_score(CHA): " << a.get_total_score(CHA) << '\n';
    std::cout << "get_all_total_scores():\n";
    a.get_all_total_scores().print_ability_array(false);
    std::cout << "get_modifier(CON): +" << a.get_modifier(CON) << '\n';
    std::cout << "get_all_modifiers():\n";
    a.get_all_modifiers().print_ability_array(true);
}

void test_Abilities_update()
{
    std::cout << "Testing Abilities_update!\n\n";
    int std_array[6] {15, 14, 13, 12, 10, 8};
    Abilities c = Abilities(std_array);
    c.print_abilities();
}

int main() {
    test_Ability();
    test_Ability_Change();
    test_Ability_Array();
    test_Abilities();
    test_Abilities_update();
    return 0;
}
