#include <algorithm>
#include <iostream>
using namespace std;

char board[2002][2002];
int prefix[2001][2001];
int best = 2000001;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C, K;
    cin >> R >> C >> K;

    for (int r = 1; r <= R; r++) {
        cin >> (board[r] + 1);
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            prefix[r][c] = prefix[r - 1][c] + prefix[r][c - 1] - prefix[r - 1][c - 1];

            if (((r + c) % 2 == 0 && board[r][c] == 'B') ||
                ((r + c) % 2 == 1 && board[r][c] == 'W')) {
                prefix[r][c]++;
            }
        }
    }

    for (int r = K; r <= R; r++) {
        for (int c = K; c <= C; c++) {
            int cur = prefix[r][c] - prefix[r - K][c] - prefix[r][c - K] + prefix[r - K][c - K];
            cur = min(cur, K * K - cur);

            if (cur < best) {
                best = cur;
            }
        }
    }

    cout << best;
}