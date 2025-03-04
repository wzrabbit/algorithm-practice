#include <algorithm>
#include <initializer_list>
#include <iostream>
#define INF 1'000'001
using namespace std;

int row_cost[101][101], col_cost[101][101];
int dp[101][101][201][2];
int R, C, move_time, fuel;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> R >> C >> move_time >> fuel;
        int regular_move_count = R + C - 2;
        int regular_time = regular_move_count * move_time;
        int M = regular_move_count - 1;

        for (int r = 1; r <= R; r++) {
            for (int c = 1; c < C; c++) {
                cin >> col_cost[r][c];
            }
        }

        for (int r = 1; r < R; r++) {
            for (int c = 1; c <= C; c++) {
                cin >> row_cost[r][c];
            }
        }

        fill(&dp[1][1][0][0], &dp[R][C][M][2], INF);
        dp[1][1][0][0] = 0;
        dp[1][1][0][1] = 0;

        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                for (int m = 0; m <= M; m++) {
                    for (int d = 0; d < 2; d++) {
                        if (d == 0 && r >= 2) {
                            dp[r][c][m][d] =
                                min(dp[r][c][m][d],
                                    dp[r - 1][c][m][0] + row_cost[r - 1][c]);
                        }

                        if (d == 1 && c >= 2) {
                            dp[r][c][m][d] =
                                min(dp[r][c][m][d],
                                    dp[r][c - 1][m][1] + col_cost[r][c - 1]);
                        }

                        if (m > 0) {
                            dp[r][c][m][d] =
                                min(dp[r][c][m][d], dp[r][c][m - 1][!d]);
                        }
                    }
                }
            }
        }

        int answer = INF;

        for (int m = 0; m <= M; m++) {
            for (int d = 0; d < 2; d++) {
                if (dp[R][C][m][d] <= fuel) {
                    answer = min(answer, regular_time + m);
                }
            }
        }

        if (answer == INF) {
            cout << -1 << '\n';
        } else {
            cout << answer << '\n';
        }
    }
}
