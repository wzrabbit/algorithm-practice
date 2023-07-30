#include <algorithm>
#include <iostream>
#define INF 99999999
using namespace std;

int dp[1001][31][3];  // dp[지난 시간][움직인 횟수][서 있는 나무번호] = 자두 개수

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T, W;
    cin >> T >> W;

    fill(&dp[0][0][1], &dp[T][W][3], -INF);
    dp[0][0][1] = 0;

    for (int i = 1; i <= T; i++) {
        int cur;
        cin >> cur;

        for (int j = 0; j <= W; j++) {
            if (cur == 1) {
                dp[i][j][1] = dp[i - 1][j][1] + 1;  // 1 -> 1
                dp[i][j][2] = dp[i - 1][j][2];      // 2 -> 2

                if (j > 0) {
                    dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][2] + 1);  // 2 -> 1
                    dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j - 1][1]);      // 1 -> 2
                }
            } else {
                dp[i][j][1] = dp[i - 1][j][1];      // 1 -> 1
                dp[i][j][2] = dp[i - 1][j][2] + 1;  // 2 -> 2

                if (j > 0) {
                    dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][2]);      // 2 -> 1
                    dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j - 1][1] + 1);  // 1 -> 2
                }
            }
        }
    }

    int best = 0;

    for (int i = 0; i <= W; i++) {
        for (int j = 1; j <= 2; j++) {
            best = max(best, dp[T][i][j]);
        }
    }

    cout << best;
}