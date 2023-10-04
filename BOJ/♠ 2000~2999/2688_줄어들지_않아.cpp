#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll dp[65][10];  // dp[n번째 수][현재 선택한 자릿수] = 경우의 수

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        fill(&dp[0][0], &dp[N][10], 0);
        dp[0][0] = 1;

        for (int r = 1; r <= N; r++) {
            for (int c = 0; c <= 9; c++) {
                for (int i = 0; i <= c; i++) {
                    dp[r][c] += dp[r - 1][i];
                }
            }
        }

        ll counts = 0;

        for (int c = 0; c <= 9; c++) {
            counts += dp[N][c];
        }

        cout << counts << '\n';
    }
}
