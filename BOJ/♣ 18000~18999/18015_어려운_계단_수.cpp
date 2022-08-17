#include <algorithm>
#include <iostream>
#define MOD 1000000000
using namespace std;

int dp[2000][2000][2][2];  // dp[i번째 수][현재 수][0 나왔는지의 여부][N-1 나왔는지의 여부]
int p[2] = {-1, 1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, B;
    cin >> N >> B;

    dp[0][B - 1][0][1] = 1;
    for (int i = 1; i < B - 1; i++)
        dp[0][i][0][0] = 1;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < B; j++) {
            for (int k = 0; k < 2; k++) {
                int prev = j + p[k];
                if (prev < 0 || prev >= B)
                    continue;

                if (j == 0) {
                    for (int l = 0; l < 2; l++) {
                        for (int m = 0; m < 2; m++) {
                            dp[i][j][1][m] += dp[i - 1][prev][l][m];
                            dp[i][j][1][m] %= MOD;
                        }
                    }
                } else if (j == B - 1) {
                    for (int l = 0; l < 2; l++) {
                        for (int m = 0; m < 2; m++) {
                            dp[i][j][l][1] += dp[i - 1][prev][l][m];
                            dp[i][j][l][1] %= MOD;
                        }
                    }
                } else {
                    for (int l = 0; l < 2; l++) {
                        for (int m = 0; m < 2; m++) {
                            dp[i][j][l][m] += dp[i - 1][prev][l][m];
                            dp[i][j][l][m] %= MOD;
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < B; i++)
        ans = (ans + dp[N - 1][i][1][1]) % MOD;

    cout << ans;
}