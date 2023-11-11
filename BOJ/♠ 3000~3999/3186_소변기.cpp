#include <iostream>
using namespace std;

char sensor[10002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int K, L, N;
    cin >> K >> L >> N;

    cin >> (sensor + 1);

    bool is_using = false;
    int state_time = 0;
    bool no_flush = true;

    for (int i = 1; i <= N; i++) {
        if (sensor[i] == '0') {
            if (is_using) {
                state_time += 1;

                if (state_time == L) {
                    is_using = false;
                    state_time = 0;
                    no_flush = false;
                    cout << i << '\n';
                }
            } else {
                state_time = 0;
            }

            continue;
        }

        if (is_using) {
            state_time = 0;
        } else {
            state_time += 1;

            if (state_time == K) {
                is_using = true;
                state_time = 0;
            }
        }
    }

    if (is_using) {
        cout << N + L - state_time << '\n';
        no_flush = false;
    }

    if (no_flush) {
        cout << "NIKAD" << '\n';
    }
}