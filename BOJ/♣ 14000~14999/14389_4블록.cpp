#include <algorithm>
#include <iostream>
using namespace std;

char raw[10][25];
char board[250];
int dp[250][4096];
int R, C;

int top_down(int no, int state) {
    int& cur = dp[no][state];

    if (no >= R * (C - 1)) {
        return 0;
    }

    if (cur != -1) {
        return cur;
    }

    cur = top_down(no + 1, state >> 1);

    if (
        (state & 1) == 0 && (state & 2) == 0 &&
        (state & (1 << R)) == 0 &&
        (state & (1 << (R + 1))) == 0 &&
        board[no] == '.' &&
        board[no + 1] == '.' &&
        board[no + R] == '.' &&
        board[no + R + 1] == '.' &&
        no % R != R - 1) {
        cur = max(cur, top_down(no + 2, ((state >> 2) | (1 << (R - 2)) | (1 << (R - 1)))) + 1);
    }

    return cur;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 0; r < R; r++) {
        cin >> raw[r];
    }

    for (int i = 0; i < R * C; i++) {
        board[i] = raw[i % R][i / R];
    }

    fill(&dp[0][0], &dp[R * C - 1][1 << (R + 1)], -1);

    cout << R * C + top_down(0, 0) * 12;
}