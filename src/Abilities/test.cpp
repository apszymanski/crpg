#include "Abilities.h"

void test_Ability()
{
    std::array<Ability, 6> array {STR, DEX, CON, INT, WIS, CHA};
    for (int i {}; i < 6; ++i) {
        if (array[size_t(i)] == i) {
            std::cout << "OK\n";
        }
    }
}

void test_Ability_Array()
{
    Ability_Array a;
    std::cout << "Ability Array size is: "<< a.get_array_size() << '\n';
    a.print_ability_array();
    int b_base[]{1,2,3,4,5,6};
    Ability_Array b(b_base);
    b.print_ability_array();
    a.set_score(CHA, 6);
    int a_cha = a.get_score(CHA);
    int b_cha = b.get_score(CHA);
    if (a_cha == b_cha) {
        std::cout << "Success!" << '\n';
    }
}

void test_Ability_Change()
{
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

}

void test_Abilities() {
    
}

int main() {
    test_Ability();
    test_Ability_Change();
    test_Ability_Array();
    return 0;
}
