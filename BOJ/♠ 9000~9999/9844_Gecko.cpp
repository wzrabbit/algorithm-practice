#include <iostream>
using namespace std;

int grid[502][502];
int dp[502][502];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            for (int i = c - 1; i <= c + 1; i++) {
                dp[r][c] = max(dp[r - 1][i] + grid[r][c], dp[r][c]);
            }
        }
    }

    int answer = 0;

    for (int c = 1; c <= C; c++) {
        answer = max(answer, dp[R][c]);
    }

    cout << answer;
}
