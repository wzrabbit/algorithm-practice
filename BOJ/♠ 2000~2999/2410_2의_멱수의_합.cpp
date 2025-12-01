#include <iostream>
#define MOD 1'000'000'000
using namespace std;

int dp[1000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    dp[0] = 1;

    for (int i = 0; i < 20; i++) {
        for (int j = (1 << i); j <= N; j++) {
            dp[j] = (dp[j] + dp[j - (1 << i)]) % MOD;
        }
    }

    cout << dp[N];
}
