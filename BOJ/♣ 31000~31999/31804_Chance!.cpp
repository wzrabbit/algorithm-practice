#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <string>
#define INF 123456789
using namespace std;

int dp[2][1000001];

void perform_dp(int start, int dp[2][1000001]) {
    fill(&dp[0][1], &dp[1][1000001], INF);
    dp[0][start] = 0;

    for (int i = 0; i <= 1; i++) {
        for (int j = start + 1; j <= 1000000; j++) {
            dp[i][j] = dp[i][j - 1];

            if (j % 2 == 0) {
                dp[i][j] = min(dp[i][j / 2], dp[i][j]);
            }

            if (i == 1 && j % 10 == 0) {
                dp[1][j] = min(dp[0][j / 10], dp[1][j]);
            }

            dp[i][j] += 1;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int A, B;
    cin >> A >> B;

    perform_dp(A, dp);

    cout << min(dp[0][B], dp[1][B]);
}
