#include <algorithm>
#include <iostream>
#define INF 999
using namespace std;

int participants[301];
int dp[301][301][301];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, K, T;
    cin >> N >> M >> K >> T;

    for (int i = 1; i <= M; i++) {
        int start, end;
        cin >> start >> end;

        for (int j = start; j < end; j++) {
            participants[j] += 1;
        }
    }

    fill(&dp[0][0][0], &dp[N][N][N + 1], -INF);
    dp[0][K][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k <= K; k++) {
                if (dp[i][j][k] == -INF) {
                    continue;
                }

                int need = T - participants[i + 1] - k;

                if (participants[i + 1] >= T) {
                    dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][k] + 1);
                    continue;
                }

                if (need <= 0) {
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + 1);
                    continue;
                }

                if (j >= need) {
                    dp[i + 1][j - need][k + need] = max(dp[i + 1][j - need][k + need], dp[i][j][k] + 1);
                }

                dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
            }
        }
    }

    int answer = -INF;

    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= K; j++) {
            answer = max(answer, dp[N][i][j]);
        }
    }

    cout << answer;
}
