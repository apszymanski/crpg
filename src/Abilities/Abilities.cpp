#include "Abilities.h"

#include <array>
#include <string>
using namespace std;

Abilities::Abilities(array<std::uint8_t, size> scores) {
    ability_scores = scores;
}

Abilities::Abilities(uint8_t) {

}

Abilities::~Abilities() {}

int main() {
    Abilities abilities;
    abilities.print_ability_score(true);
    return 0;
}