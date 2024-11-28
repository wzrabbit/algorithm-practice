#include <iostream>
#define MOD 1'000'000'007
typedef long long ll;
using namespace std;

ll dp[3001][3001]
     [2];  // dp[몇 번째][연속 선택 횟수][K번 연속 고른 적 있는가] = 가짓수
ll row_sum[3001];
bool is_required[3001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> is_required[i];
    }

    dp[0][0][0] = 1;

    for (int r = 1; r <= N; r++) {
        if (!is_required[r]) {
            for (int c = 0; c <= K; c++) {
                for (int i = 0; i < 2; i++) {
                    dp[r][0][i] = (dp[r][0][i] + dp[r - 1][c][i]) % MOD;
                }
            }
        }

        for (int c = 1; c <= K; c++) {
            for (int i = 0; i < 2; i++) {
                dp[r][c][i | (c == K)] =
                    (dp[r][c][i | (c == K)] + dp[r - 1][c - 1][i]) % MOD;
            }
        }
    }

    ll answer = 0;

    for (int i = 0; i <= K; i++) {
        answer = (answer + dp[N][i][1]) % MOD;
    }

    cout << answer;
}
