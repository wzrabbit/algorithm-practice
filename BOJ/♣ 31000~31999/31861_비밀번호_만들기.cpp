#include <algorithm>
#include <iostream>
#define MOD 1'000'000'007
typedef long long ll;
using namespace std;

ll dp[1001][26];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    fill(&dp[1][0], &dp[1][26], 1);

    for (int i = 2; i <= M; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                if (abs(j - k) >= N) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
        }
    }

    ll answer = 0;

    for (int i = 0; i < 26; i++) {
        answer = (answer + dp[M][i]) % MOD;
    }

    cout << answer;
}
