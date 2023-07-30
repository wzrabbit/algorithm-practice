#include <algorithm>
#include <iostream>
using namespace std;

int dp[11][11];
int N, sum;

int get_simulated_sum() {
    for (int r = 2; r <= N; r++) {
        for (int c = 1; c <= N - r + 1; c++) {
            dp[r][c] = dp[r - 1][c] + dp[r - 1][c + 1];
        }
    }

    return dp[N][1];
}

int main() {
    cin >> N >> sum;

    for (int i = 1; i <= N; i++) {
        dp[1][i] = i;
    }

    do {
        if (get_simulated_sum() == sum) {
            for (int i = 1; i <= N; i++) {
                cout << dp[1][i] << ' ';
            }

            break;
        }
    } while (next_permutation(&dp[1][1], &dp[1][N + 1]));
}