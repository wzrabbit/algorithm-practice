#include <iostream>
using namespace std;

bool grid[17][17];
int dp[3][17][17];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> grid[r][c];
        }
    }

    dp[0][1][2] = 1;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (c + 1 <= N && !grid[r][c + 1]) {
                dp[0][r][c + 1] += dp[0][r][c];
            }

            if (r + 1 <= N && c + 1 <= N && !grid[r][c + 1] &&
                !grid[r + 1][c] && !grid[r + 1][c + 1]) {
                for (int i = 0; i < 3; i++) {
                    dp[1][r + 1][c + 1] += dp[i][r][c];
                }
            }
        }
    }
}