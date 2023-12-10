#include <algorithm>
#include <iostream>
#define INF 5'000'000'001
typedef long long ll;
using namespace std;

ll dp[10001][501];
ll info[10001];
ll pos[1001];
ll cost[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int C, E, D, N;
    cin >> C >> E >> D >> N;

    for (int i = 1; i <= N; i++) {
        cin >> pos[i];
        pos[i] += pos[i - 1];
    }

    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
    }

    for (int i = 1; i <= N; i++) {
        if (pos[i] <= D) {
            info[pos[i]] = cost[i];
        }
    }

    fill(&dp[0][0], &dp[D][C + 1], INF);
    dp[0][C] = 0;

    for (int r = 1; r <= D; r++) {
        for (int c = 0; c <= C; c++) {
            if (c + E <= C) {
                dp[r][c] = dp[r - 1][c + E];
            }

            if (info[r] != 0) {
                dp[r][c] = min(dp[r][c], dp[r][c - 1] + info[r]);
            }
        }
    }

    ll minimum_cost = INF;

    for (int c = 0; c <= C; c++) {
        minimum_cost = min(minimum_cost, dp[D][c]);
    }

    if (minimum_cost == INF) {
        cout << -1;
    } else {
        cout << minimum_cost;
    }
}