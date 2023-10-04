#include <algorithm>
#include <iostream>
#define INF 99999
using namespace std;

int dp[20001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int price, N;
        cin >> price >> N;

        fill(dp, dp + 20001, INF);
        dp[0] = 0;

        for (int i = 1; i <= N; i++) {
            int coin;
            cin >> coin;

            for (int j = 20000; j >= coin; j--) {
                if (dp[j - coin] != INF) {
                    dp[j] = min(dp[j - coin] + 1, dp[j]);
                }
            }
        }

        for (int i = price; i <= 20000; i++) {
            if (dp[i] != INF) {
                cout << i << ' ' << dp[i] << '\n';
                break;
            }
        }
    }
}