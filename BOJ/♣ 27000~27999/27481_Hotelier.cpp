#include <iostream>
using namespace std;

bool state[10];
char query[200005];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int Q;
    cin >> Q;

    cin >> (query + 1);

    for (int i = 1; i <= Q; i++) {
        if (query[i] == 'L') {
            for (int j = 0; j <= 9; j++) {
                if (!state[j]) {
                    state[j] = true;
                    break;
                }
            }

            continue;
        }

        if (query[i] == 'R') {
            for (int j = 9; j >= 0; j--) {
                if (!state[j]) {
                    state[j] = true;
                    break;
                }
            }

            continue;
        }

        state[query[i] - '0'] = false;
    }

    for (int i = 0; i <= 9; i++) {
        cout << state[i];
    }
}