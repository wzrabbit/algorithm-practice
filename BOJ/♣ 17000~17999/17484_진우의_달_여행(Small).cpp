#include <iostream>
#define INF 12'34
using namespace std;

int grid[8][8];
int dp[3][8][8];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    fill(&dp[0][0][1], &dp[2][R][C + 2], INF);

    for (int l = 0; l < 3; l++) {
        for (int c = 1; c <= C; c++) {
            dp[l][0][c] = 0;
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            dp[0][r][c] = min(dp[1][r - 1][c - 1], dp[2][r - 1][c - 1]) + grid[r][c];
            dp[1][r][c] = min(dp[0][r - 1][c], dp[2][r - 1][c]) + grid[r][c];
            dp[2][r][c] = min(dp[0][r - 1][c + 1], dp[1][r - 1][c + 1]) + grid[r][c];
        }
    }

    int minimum_fuel = INF;

    for (int l = 0; l < 3; l++) {
        for (int c = 1; c <= C; c++) {
            minimum_fuel = min(minimum_fuel, dp[l][R][c]);
        }
    }

    cout << minimum_fuel;
}