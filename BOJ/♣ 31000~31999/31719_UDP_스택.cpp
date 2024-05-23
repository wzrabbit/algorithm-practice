#include <algorithm>
#include <iostream>
using namespace std;

struct UDPStack {
    int lo, hi;
    bool open;
};

UDPStack S[3];
int turn = 1;
bool success = true;

void init() {
    turn = 1;
    success = true;

    S[0] = {lo : 0, hi : 0, open : true};
    S[1] = {lo : 0, hi : 0, open : false};
    S[2] = {lo : 0, hi : 0, open : false};
}

void open_stack(int index) {
    turn = S[index].hi + 1;
    S[index].lo = 0;
    S[index].hi = 0;
    S[index].open = true;
}

void trash_values() {
    for (int i = 0; i < 2; i++) {
        int prev_opened_index = -1;

        for (int j = 0; j < 3; j++) {
            if (S[j].open) {
                prev_opened_index = j;
                break;
            }
        }

        for (int j = 0; j < 3; j++) {
            if (j == prev_opened_index) {
                continue;
            }

            if (S[j].lo == turn) {
                open_stack(j);
                S[prev_opened_index].open = false;
                break;
            }
        }
    }
}

bool append_value(int cur) {
    if (cur == turn) {
        turn += 1;
        return true;
    }

    for (int i = 0; i < 3; i++) {
        if (S[i].open) {
            continue;
        }

        if (cur == S[i].hi + 1) {
            S[i].hi += 1;
            return true;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (S[i].open) {
            continue;
        }

        if (S[i].lo == 0) {
            S[i].lo = cur;
            S[i].hi = cur;
            return true;
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        init();

        for (int i = 1; i <= N; i++) {
            int cur;
            cin >> cur;

            if (!append_value(cur)) {
                success = false;
            }

            trash_values();
        }

        if (success && turn == N + 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
