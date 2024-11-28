#include <iostream>
#include <queue>
using namespace std;

int grid[1001][1001];
int dp[1002][1002];
int dp2[1002][1002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
            dp[r][c] = grid[r][c];
            dp2[r][c] = grid[r][c];
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            dp[r][c] = max(dp[r][c], dp[r - 1][c] + grid[r][c]);
            dp[r][c] = max(dp[r][c], dp[r][c - 1] + grid[r][c]);
        }
    }

    for (int r = R; r >= 1; r--) {
        for (int c = 1; c <= C; c++) {
            dp2[r][c] = max(dp2[r][c], dp2[r + 1][c] + grid[r][c]);
            dp2[r][c] = max(dp2[r][c], dp2[r][c - 1] + grid[r][c]);
        }
    }

    int answer = grid[1][1];

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            answer = max(answer, dp[r][c]);
            answer = max(answer, dp2[r][c]);
        }
    }

    cout << answer;
}
