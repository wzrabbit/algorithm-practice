#include <algorithm>
#include <iostream>
#define INF 1'000'000'000
using namespace std;

int dp[201][201];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, A, B;
    cin >> N >> A >> B;

    fill(&dp[0][0], &dp[200][201], INF);
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;

        for (int j = 200; j >= 0; j--) {
            for (int k = 200; k >= 0; k--) {
                int next_a = min(200, j + a);
                int next_b = min(200, k + b);
                dp[next_a][next_b] = min(dp[j][k] + 1, dp[next_a][next_b]);
            }
        }
    }

    int answer = INF;

    for (int i = A; i <= 200; i++) {
        for (int j = B; j <= 200; j++) {
            answer = min(answer, dp[i][j]);
        }
    }

    if (answer == INF) {
        cout << -1;
    } else {
        cout << answer;
    }
}
