#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int dp[5000][5000];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    string S, T;
    cin >> S >> T;

    for (int c = 0; c < N; c++) {
        if (S[c] == T[0]) {
            dp[0][c] = 1;
        }
    }

    for (int r = 1; r < M; r++) {
        for (int c = 0; c < N; c++) {
            dp[r][c] = max(c > 0 ? dp[r - 1][c - 1] : 0,
                           c < N - 1 ? dp[r - 1][c + 1] : 0);

            if (T[r] == S[c]) {
                dp[r][c] += 1;
            }
        }
    }

    int best_score = 0;
    for (int c = 0; c < N; c++) {
        best_score = max(best_score, dp[M - 1][c]);
    }

    cout << best_score;
}