#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> visited[51];
int G, P;
bool success = false;

void simulate(string S, int turn) {
    if (visited[turn].find(S) != visited[turn].end()) {
        return;
    }

    if (turn == P + 1) {
        success = true;
        return;
    }

    visited[turn].insert(S);

    for (int i = 0; i < G - 1; i++) {
        if (S[i] != 'R' && S[i + 1] != 'L') {
            char prev_l = S[i];
            char prev_r = S[i + 1];

            S[i] = 'R';
            S[i + 1] = 'L';

            simulate(S, turn + 1);

            S[i] = prev_l;
            S[i + 1] = prev_r;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string S;

    cin >> G >> P >> S;

    simulate(S, 1);

    cout << success;
}
