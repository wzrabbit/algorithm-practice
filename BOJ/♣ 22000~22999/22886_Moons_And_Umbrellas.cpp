#include <algorithm>
#include <iostream>
#include <string>
#define INF 1'000'000'000
using namespace std;

int dp[1000][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int X, Y;
        string S;
        cin >> X >> Y >> S;
        int N = S.size();

        fill(&dp[0][0], &dp[999][2], INF);

        if (S[0] != 'C') {
            dp[0][1] = 0;
        }

        if (S[0] != 'J') {
            dp[0][0] = 0;
        }

        for (int i = 1; i < N; i++) {
            if (S[i] != 'C') {
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + X);
            }

            if (S[i] != 'J') {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + Y);
            }
        }

        cout << "Case #" << t << ": " << min(dp[N - 1][0], dp[N - 1][1])
             << '\n';
    }
}
