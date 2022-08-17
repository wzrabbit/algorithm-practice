#include <algorithm>
#include <iostream>
#define INF 2000000
using namespace std;

int dp[4001][4001];  // dp[날짜][슬픈 횟수] = 성적 합
int a_score[4001];
int b_score[4001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> a_score[i] >> b_score[i];

    fill(&dp[0][0], &dp[4000][4001], INF);
    dp[1][0] = min(a_score[1], b_score[1]);

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[i][j] == INF)
                continue;

            // 성적 안 바꾸는 경우 (a)
            if (dp[i][j] <= a_score[i + 1] * i)
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a_score[i + 1]);
            else
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + a_score[i + 1]);

            // 성적 바꾸는 경우 (b)
            if (dp[i][j] <= b_score[i + 1] * i)
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + b_score[i + 1]);
            else
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + b_score[i + 1]);
        }
    }

    int ans;
    for (int i = 0; i < N; i++) {
        if (dp[N][i] < INF) {
            ans = i;
            break;
        }
    }

    cout << ans;
}