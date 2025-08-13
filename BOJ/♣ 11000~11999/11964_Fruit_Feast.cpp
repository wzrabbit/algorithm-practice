#include <iostream>
using namespace std;

bool dp[2][5000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T, A, B;
    cin >> T >> A >> B;

    dp[0][0] = true;
    dp[1][0] = true;

    for (int i = 1; i <= T; i++) {
        if (i >= A && dp[0][i - A] || i >= B && dp[0][i - B]) {
            dp[0][i] = true;
        }
    }

    for (int i = 1; i <= T; i++) {
        if (i >= A && dp[1][i - A] || i >= B && dp[1][i - B]) {
            dp[1][i] = true;
        }

        if (i * 2 <= T && dp[0][i * 2] || i * 2 + 1 <= T && dp[0][i * 2 + 1]) {
            dp[1][i] = true;
        }
    }

    for (int i = T; i >= 0; i--) {
        if (dp[0][i] || dp[1][i]) {
            cout << i;
            return 0;
        }
    }
}
