#include <algorithm>
#include <iostream>
#define INF 1'000'000'000
using namespace std;

struct Boost {
    int cost, power;
};

int dp[101][5002];  // dp[소모한 시간][s의 값] = 당근의 개수
Boost boosts[101];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> boosts[i].cost >> boosts[i].power;
    }

    fill(&dp[0][0], &dp[100][5002], -INF);
    dp[0][1] = 0;

    for (int r = 1; r <= K; r++) {
        for (int c = 1; c <= 5000; c++) {
            dp[r][c] = dp[r - 1][c] + c;

            for (int i = 1; i <= N; i++) {
                if (c - boosts[i].power >= 0) {
                    int next_carrot_count = dp[r - 1][c - boosts[i].power] - boosts[i].cost;

                    if (next_carrot_count >= 0) {
                        dp[r][c] = max(dp[r][c], next_carrot_count);
                    }
                }
            }
        }
    }

    int max_carrot_count = 0;

    for (int i = 1; i <= 5001; i++) {
        max_carrot_count = max(max_carrot_count, dp[K][i]);
    }

    cout << max_carrot_count;
}
