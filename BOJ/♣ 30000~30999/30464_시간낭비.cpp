#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <queue>
#define INF 123'456'789
using namespace std;

int arr[200001];
int dp[3][200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    fill(&dp[0][1], &dp[2][N + 1], -1);
    dp[0][1] = 0;

    for (int i = 0; i < 3; i++) {
        if (i == 1) {
            for (int j = N - 1; j >= 1; j--) {
                if (dp[i][j] == -1) {
                    continue;
                }

                int next_n = j - arr[j];

                if (next_n < 1) {
                    continue;
                }

                dp[i][next_n] = max(dp[i][j] + 1, dp[i][next_n]);
                dp[i + 1][next_n] = max(dp[i][j] + 1, dp[i + 1][next_n]);
            }

            continue;
        }

        for (int j = 1; j <= N - 1; j++) {
            if (dp[i][j] == -1) {
                continue;
            }

            int next_n = j + arr[j];

            if (next_n > N) {
                continue;
            }

            dp[i][next_n] = max(dp[i][j] + 1, dp[i][next_n]);

            if (i < 2) {
                dp[i + 1][next_n] = max(dp[i][j] + 1, dp[i + 1][next_n]);
            }
        }
    }

    int answer = max({dp[0][N],
                      dp[1][N],
                      dp[2][N]});

    cout << answer;
}
