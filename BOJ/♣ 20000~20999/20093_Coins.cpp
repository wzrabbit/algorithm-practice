#include "coins.h"
using namespace std;

vector<int> coin_flips(vector<int> coins, int cursed) {
    int xor_value = 0;

    for (int i = 0; i <= 63; i++) {
        xor_value ^= coins[i] * i;
    }

    int xor_key = xor_value ^ cursed;
    vector<int> flips(1, xor_key);
    return flips;
}

int find_coin(vector<int> coins) {
    int xor_value = 0;

    for (int i = 0; i <= 63; i++) {
        xor_value ^= coins[i] * i;
    }

    return xor_value;
}
