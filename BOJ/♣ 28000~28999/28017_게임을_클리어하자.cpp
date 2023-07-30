#include <algorithm>
#include <iostream>
#define INF 5'000'001
using namespace std;

int grid[501][501];
int dp[501][501];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    fill(&dp[1][1], &dp[N][M + 1], INF);

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            cin >> grid[r][c];

            for (int i = 1; i <= M; i++) {
                if (i == c) continue;
                dp[r][c] = min(dp[r - 1][i] + grid[r][c], dp[r][c]);
            }
        }
    }

    int best = INF;

    for (int c = 1; c <= M; c++) {
        best = min(best, dp[N][c]);
    }

    cout << best;
}