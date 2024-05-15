#include "util.h"

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// returns the sum of an int array of a certain length
int int_array_sum(int* a, size_t length) {
    int sum = 0;
    for (uint i = 0; i < length; i++) {
        sum = sum + a[i];
    }
    return sum;
}

// returns the index of the min of an int array of a certain length
int int_array_min_index(int* a, size_t length) {
    int min_index = 0;
    for (uint i = 0; i < length; i++) {
        if (a[i] <= a[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

// reassign ability score to a different ability
int reassign(int* addr, size_t length, uint from, uint to) {
    if (from > length || to > length) {
        return -1;
    }
    int swap = addr[to];
    addr[to] = addr[from];
    addr[from] = swap;
    return 0;
}

// print ability names and respective scores
void print_ability_score(string* ability_names, int* ability_scores, size_t length, bool total_flag){

    for (uint i = 0; i < length; i++){
        cout << ability_names[i] + (string)":\t" << ability_scores[i] << '\n';
    }
    string total = total_flag ? "Total:\t" + to_string(int_array_sum(ability_scores, length)) + "\n" : (string)"\n";
    cout << total << endl;
}