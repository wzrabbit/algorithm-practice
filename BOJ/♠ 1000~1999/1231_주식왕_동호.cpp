#include <algorithm>
#include <iostream>
#define INF -2100000000
using namespace std;

int price[11][51];
int dp[500001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int C, D, M;
    cin >> C >> D >> M;

    for (int c = 1; c <= C; c++) {
        for (int r = 1; r <= D; r++) {
            cin >> price[r][c];
        }
    }

    for (int d = 2; d <= D; d++) {
        int max_diff = 0;
        fill(dp + 1, dp + M + 1, INF);

        for (int i = 1; i <= C; i++) {
            int current_price = price[d - 1][i];
            int margin = price[d][i] - price[d - 1][i];

            for (int j = current_price; j <= M; j++) {
                dp[j] = max(dp[j], dp[j - current_price] + margin);
                max_diff = max(max_diff, dp[j]);
            }
        }

        M += max_diff;
    }

    cout << M;
}