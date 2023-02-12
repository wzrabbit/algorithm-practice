#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

double dp[402][402][402];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int B, L, N;
        cin >> B >> L >> N;

        fill(&dp[1][1][1], &dp[L + 1][L + 1][L + 2], 0);
        dp[1][1][1] = B * 750;

        for (int l = 1; l <= L; l++) {
            for (int r = 1; r <= l; r++) {
                for (int c = 1; c <= l; c++) {
                    if (dp[l][r][c] > 0) {
                        double left = max(dp[l][r][c] - 250.0, 0.0);
                        double left_divided = left / 3;

                        dp[l + 1][r][c] += left_divided;
                        dp[l + 1][r + 1][c] += left_divided;
                        dp[l + 1][r + 1][c + 1] += left_divided;
                        dp[l][r][c] = min(250.0, dp[l][r][c]);
                    }
                }
            }
        }
        
        int id = 0;
        for (int r = 1; r <= L; r++) {
            for (int c = 1; c <= r; c++) {
                id += 1;
                if (id == N) {
                    cout << fixed << setprecision(7) << "Case #" << t << ": " << dp[L][r][c] << '\n';
                }
            }
        }
    }
}
