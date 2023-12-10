#include <iostream>
using namespace std;

int dp[31];

int main() {
    int N;
    cin >> N;

    if (N % 2 == 1) {
        cout << 0;
        return 0;
    }

    dp[2] = 3;

    for (int i = 4; i <= N; i += 2) {
        dp[i] = dp[i - 2] * 3 + 2;

        for (int j = 2; j <= i - 4; j += 2) {
            dp[i] += dp[j] * 2;
        }
    }

    cout << dp[N];
}