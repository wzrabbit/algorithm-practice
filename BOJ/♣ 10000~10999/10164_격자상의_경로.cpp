#include <iostream>
using namespace std;

int dp[2][16][16];

int main() {
    int R, C, D;
    cin >> R >> C >> D;

    int circle_r = (D - 1) / C + 1;
    int circle_c = (D - 1) % C + 1;

    dp[0][1][1] = 1;

    for (int i = 0; i < 2; i++) {
        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                dp[i][r][c] += dp[i][r - 1][c] + dp[i][r][c - 1];

                if (r == circle_r && c == circle_c && i == 1) {
                    dp[1][r][c] += dp[0][r - 1][c] + dp[0][r][c - 1];
                }
            }
        }
    }

    cout << dp[D != 0][R][C];
}