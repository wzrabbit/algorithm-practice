#include <algorithm>
#include <initializer_list>
#include <iostream>
#define INF 500000001
using namespace std;

int dp[5001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int L, T, a, b, c;
    int best = INF;
    cin >> L >> T;

    fill(dp + 1, dp + L + 1, INF);

    for (int i = 1; i <= T; i++) {
        cin >> a >> b >> c;

        for (int j = L; j >= 0; j--) {
            dp[j] = min({dp[j],
                         j >= 1 && dp[j - 1] != INF ? dp[j - 1] + a : INF,
                         j >= 2 && dp[j - 2] != INF ? dp[j - 2] + b : INF,
                         j >= 3 && dp[j - 3] != INF ? dp[j - 3] + c : INF});

            best = min(best, dp[L]);
        }
    }

    cout << dp[L];
}