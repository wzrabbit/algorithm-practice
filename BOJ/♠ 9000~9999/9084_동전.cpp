#include <algorithm>
#include <iostream>
using namespace std;

int coin[20];
int dp[10001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> coin[i];
        }

        int M;
        cin >> M;

        fill(dp, dp + M + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = coin[i]; j <= M; j++) {
                dp[j] += dp[j - coin[i]];
            }
        }

        cout << dp[M] << '\n';
    }
}