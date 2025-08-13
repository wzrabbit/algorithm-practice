#include <iostream>
using namespace std;

int arr[26][26];
int dp[26][26];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= r; c++) {
            cin >> arr[r][c];
        }
    }

    dp[1][1] = arr[1][1];

    for (int r = 1; r <= N - 1; r++) {
        for (int c = 1; c <= N; c++) {
            dp[r + 1][c] = max(dp[r][c] + arr[r + 1][c], dp[r + 1][c]);
            dp[r + 1][c + 1] =
                max(dp[r][c] + arr[r + 1][c + 1], dp[r + 1][c + 1]);
        }
    }

    int answer = 0;

    for (int c = 1; c <= N; c++) {
        answer = max(answer, dp[N][c]);
    }

    cout << answer;
}
