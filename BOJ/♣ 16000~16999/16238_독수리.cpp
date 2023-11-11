#include <algorithm>
#include <iostream>
using namespace std;

int arr[1001];
int dp[1001][1001];
int N;

void perform_dp() {
    for (int c = 1; c <= N; c++) {
        dp[1][c] = arr[c];
    }

    for (int r = 2; r <= N; r++) {
        int prev_best = 0;

        for (int c = 1; c <= N; c++) {
            prev_best = max(prev_best, dp[r - 1][c - 1]);
            dp[r][c] = prev_best + max(0, arr[c] - r + 1);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    perform_dp();

    int left_best = 0;

    for (int r = 1; r <= N; r++) {
        left_best = max(left_best, dp[r][N]);
    }

    fill(&dp[1][1], &dp[N][N + 1], 0);
    reverse(arr + 1, arr + N + 1);

    perform_dp();

    int right_best = 0;

    for (int r = 1; r <= N; r++) {
        right_best = max(right_best, dp[r][N]);
    }

    cout << max(left_best, right_best);
}