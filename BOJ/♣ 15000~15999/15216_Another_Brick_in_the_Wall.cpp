#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C, N;
    cin >> R >> C >> N;

    int cur_r = 1;
    int cur_c = 0;
    bool success = true;

    for (int i = 1; i <= N; i++) {
        int brick;
        cin >> brick;

        cur_c += brick;

        if (cur_c == C) {
            cur_r += 1;
            cur_c = 0;
        }

        if (cur_c > C) {
            success = false;
            break;
        }

        if (cur_r == R + 1) {
            break;
        }
    }

    if (success && cur_r == R + 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}