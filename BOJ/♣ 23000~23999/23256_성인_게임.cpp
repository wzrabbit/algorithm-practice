#include <iostream>
#define MOD 1'000'000'007
typedef long long ll;
using namespace std;

ll dp[2][1000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    dp[0][1] = 3;
    dp[1][1] = 4;

    for (int i = 2; i <= 1000000; i++) {
        dp[0][i] = (dp[0][i - 1] * 3 + dp[1][i - 1]) % MOD;
        dp[1][i] = (dp[0][i - 1] * 4 + dp[1][i - 1] * 2) % MOD;
    }

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        cout << (dp[0][N] + dp[1][N]) % MOD << '\n';
    }
}
