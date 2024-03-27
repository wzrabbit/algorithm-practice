#include <algorithm>
#include <iostream>
#define INF 1'000'000'000'000'000'000
typedef long long ll;
using namespace std;

ll arr[2005];
ll dp[1005][2005];  // dp[횟수][일] = 점수

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    ll A, D;
    cin >> A >> D;

    fill(&dp[0][0], &dp[N + 1][N + D + 2], -INF);
    dp[0][1] = 0;

    for (int r = 0; r < N; r++) {
        for (int c = 1; c <= N; c++) {
            dp[r][c + 1] = max(dp[r][c + 1], dp[r][c] + arr[c]);
            dp[r + 1][c + D] = max(dp[r + 1][c + D], dp[r][c] + A);
        }
    }

    for (int r = 0; r <= N; r++) {
        ll best = -INF;

        for (int c = 1; c <= N + D + 1; c++) {
            best = max(best, dp[r][c]);
        }

        if (best >= M) {
            cout << r;
            return 0;
        }
    }

    cout << -1;
}
