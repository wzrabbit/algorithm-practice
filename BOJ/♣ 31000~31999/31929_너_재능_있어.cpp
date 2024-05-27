#include <algorithm>
#include <iostream>
#define INF 123456789
using namespace std;

int dp[1001][1001][2];  // dp[승리 횟수][패배 횟수][보호권 경계선 여부] = 최고 점수
int win_score[1001];
int lose_score[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int W;
    cin >> W;

    for (int i = 1; i <= W; i++) {
        cin >> win_score[i];
    }

    int L;
    cin >> L;

    for (int i = 1; i <= L; i++) {
        cin >> lose_score[i];
    }

    int K;
    cin >> K;

    fill(&dp[0][0][0], &dp[W][L][2], -INF);
    dp[0][0][0] = 0;

    for (int w = 0; w <= W; w++) {
        for (int l = 0; l <= L; l++) {
            if (w == 0 && l == 0) {
                continue;
            }

            if (w > 0) {
                int next_score = max(dp[w - 1][l][0], dp[w - 1][l][1]) + win_score[w];
                bool is_protected = next_score % K != 0;

                dp[w][l][is_protected] = max(dp[w][l][is_protected], next_score);
            }

            if (l > 0) {
                int b = (dp[w][l - 1][1] + (K * 5000)) % K;
                int next_score = max(
                    dp[w][l - 1][0] - lose_score[l],
                    dp[w][l - 1][1] - min(lose_score[l], b));
                bool is_protected = next_score % K != 0;

                dp[w][l][is_protected] = max(dp[w][l][is_protected], next_score);
            }
        }
    }

    cout << max(dp[W][L][0], dp[W][L][1]) << '\n';
}
