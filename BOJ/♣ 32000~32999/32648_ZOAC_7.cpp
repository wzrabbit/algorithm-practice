#include <iostream>
using namespace std;

int grid[2002][2002];
int dp[4][2002][2002];
int dp2[4][2002][2002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            char cur;
            cin >> cur;

            switch (cur) {
                case 'Z':
                    grid[r][c] = 0;
                    break;
                case 'O':
                    grid[r][c] = 1;
                    break;
                case 'A':
                    grid[r][c] = 2;
                    break;
                case 'C':
                    grid[r][c] = 3;
                    break;
            }
        }
    }

    for (int i = 0; i <= 3; i++) {
        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                dp[i][r][c] =
                    max(dp[i][r - 1][c], dp[i][r][c - 1]) + (grid[r][c] == i);
            }
        }
    }

    for (int i = 0; i <= 3; i++) {
        for (int r = R; r >= 1; r--) {
            for (int c = C; c >= 1; c--) {
                dp2[i][r][c] =
                    max(dp2[i][r + 1][c], dp2[i][r][c + 1]) + (grid[r][c] == i);
            }
        }
    }

    for (int i = 0; i <= 3; i++) {
        int best = 0;

        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                best = max(best, dp[i][r][c] +
                                     max(dp2[i][1][c + 1], dp2[i][r + 1][1]));
            }
        }

        cout << best << ' ';
    }
}
