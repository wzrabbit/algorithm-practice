#include <iostream>
typedef long long ll;
using namespace std;

ll dp[101][21];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int S, K;
    cin >> S >> K;

    dp[0][0] = 1;

    for (int i = 1; i <= S; i++) {
        for (int j = 1; j <= K; j++) {
            for (int k = 1; k <= i; k++) {
                dp[i][j] = max(dp[i][j], dp[i - k][j - 1] * k);
            }
        }
    }

    cout << dp[S][K];
}
