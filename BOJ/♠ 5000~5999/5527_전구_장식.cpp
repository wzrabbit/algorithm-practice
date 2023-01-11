#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> combos;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int combo = 0;
    bool prev_state = false;

    for (int i = 0; i < N; i++) {
        int cur;
        cin >> cur;
        bool cur_state = cur % 2 == i % 2;

        if (cur_state == prev_state) {
            combo += 1;
        } else {
            prev_state = cur_state;
            combos.push_back(combo);
            combo = 1;
        }
    }

    combos.push_back(combo);
    combos.push_back(0);

    int best = 0;
    for (size_t i = 0; i < combos.size() - 2; i++) {
        best = max(best, combos[i] + combos[i + 1] + combos[i + 2]);
    }

    cout << best;
}