#include "Abilities.h"

void test_ability_array() {
    Ability_Array a;
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

int main() {
    test_ability_array();
    return 0;
}
