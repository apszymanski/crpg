#include "util.h"

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main() {

    // array of ability names
    string ability_names[6] = {"STR", "DEX", "CON", "INT", "WIS", "CHA"};

    // array of ability scores
    int ability_scores[] = {15, 14, 13, 12, 10, 8};

    
    print_ability_score(ability_names, ability_scores, 6, true);
    cout << "Are you happy with your scores?\n";
    cout << "0 Yes\n" << "1 No\n";
    uint response;
    cin >> response;
    
    while (response != 0) {
        cout << "Which ability score do you want to reassign?\n";
        cout << "1 STR\n"
             << "2 DEX\n"
             << "3 CON\n"
             << "4 INT\n"
             << "5 WIS\n"
             << "6 CHA\n";
        int get;
        cin >>  get;
        cout << "You chose ability score " << ability_scores[get-1] << "\n";
        cout << "To which ability do you want to assign this score?\n";
        cout << "1 STR\n"
             << "2 DEX\n"
             << "3 CON\n"
             << "4 INT\n"
             << "5 WIS\n"
             << "6 CHA\n";
        int set;
        cin >> set;
        reassign(ability_scores, 6, get-1, set-1);
        print_ability_score(ability_names, ability_scores, 6, true);
        cout << "Are you happy with your scores?\n";
        cout << "0 Yes\n" << "1 No\n";
        cin >> response;
    }
    
}