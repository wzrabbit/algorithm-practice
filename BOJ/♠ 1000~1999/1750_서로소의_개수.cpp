#include <algorithm>
#include <iostream>
#define MOD 10000003
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int dp[51][100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, x;
    cin >> N >> x;

    dp[1][x] = 1;

    for (int i = 2; i <= N; i++) {
        int x;
        cin >> x;

        dp[i][x] = 1;
        for (int j = 1; j <= 100000; j++) {
            int gcd_res = gcd(j, x);
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            dp[i][gcd_res] = (dp[i][gcd_res] + dp[i - 1][j]) % MOD;
        }
    }

    cout << dp[N][1];
}