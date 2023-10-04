#include <algorithm>
#include <iostream>
#define MOD 9901
using namespace std;

int dp[200][16384];
int R, C;

int top_down(int no, int state) {
    int &cur = dp[no][state];

    if (no >= R * C + 1) {
        if (no == R * C + 1 && state == 0) {
            return 1;
        }

        return 0;
    }

    if (cur != -1) {
        return cur;
    }

    cur = 0;

    if (state & 1) {
        cur = top_down(no + 1, state >> 1);
    } else {
        cur += top_down(no + 1, (state >> 1) | (1 << (C - 1)));

        if ((state & 2) == 0 && no % C != 0) {
            cur += top_down(no + 2, state >> 2);
        }
    }

    return cur % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    fill(&dp[1][0], &dp[R * C][1 << C], -1);

    cout << top_down(1, 0);
}