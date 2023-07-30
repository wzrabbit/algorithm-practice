#include <iostream>
#define MOD 100000
using namespace std;

int dp[2][2][101][101];  // dp[직전 방향][가능 여부][R][C] (0: ↓, 1: →)

int main() {
    int R, C;
    cin >> R >> C;

    dp[0][0][1][1] = 1;
    dp[1][0][1][1] = 1;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (r == 1 && c == 1) {
                continue;
            }

            dp[0][0][r][c] = dp[1][1][r - 1][c] % MOD;
            dp[1][0][r][c] = dp[0][1][r][c - 1] % MOD;

            dp[0][1][r][c] = (dp[0][0][r - 1][c] + dp[0][1][r - 1][c]) % MOD;
            dp[1][1][r][c] = (dp[1][0][r][c - 1] + dp[1][1][r][c - 1]) % MOD;
        }
    }

    int answer = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            answer += dp[i][j][R][C];
        }
    }

    cout << answer % MOD;
}