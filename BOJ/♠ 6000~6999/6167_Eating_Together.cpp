#include <algorithm>
#include <iostream>
#define INF 98'765
using namespace std;

int arr[30001];
int dp[2][4][30001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    fill(&dp[0][0][0], &dp[1][3][30001], INF);

    for (int l = 0; l < 2; l++) {
        for (int r = 1; r <= 3; r++) {
            dp[l][r][0] = 0;
        }
    }

    for (int c = 1; c <= N; c++) {
        dp[0][1][c] = dp[0][1][c - 1] + (arr[c] != 1);
        dp[1][3][c] = dp[1][3][c - 1] + (arr[c] != 3);
    }

    for (int r = 2; r <= 3; r++) {
        for (int c = 1; c <= N; c++) {
            dp[0][r][c] = dp[0][r][c - 1] + (arr[c] != r);

            for (int i = 1; i <= r - 1; i++) {
                dp[0][r][c] = min(dp[0][r][c], dp[0][r - i][c - 1] + (arr[c] != r));
            }
        }
    }

    for (int r = 2; r >= 1; r--) {
        for (int c = 1; c <= N; c++) {
            dp[1][r][c] = dp[1][r][c - 1] + (arr[c] != r);

            for (int i = 1; i <= 3 - r; i++) {
                dp[1][r][c] = min(dp[1][r][c], dp[1][r + i][c - 1] + (arr[c] != r));
            }
        }
    }

    int answer = INF;

    for (int l = 0; l < 2; l++) {
        for (int r = 1; r <= 3; r++) {
            answer = min(answer, dp[l][r][N]);
        }
    }

    cout << answer;
}
