#include <algorithm>
#include <iostream>
using namespace std;

int arr[50001];
int prefix[50001];
int dp[3][50001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + arr[i];
    }

    int K;
    cin >> K;

    for (int r = 0; r < 3; r++) {
        for (int c = K * (r + 1); c <= N; c++) {
            dp[r][c] = max(
                dp[r][c - 1],
                prefix[c] - prefix[c - K] + (r > 0 ? dp[r - 1][c - K] : 0));
        }
    }

    cout << dp[2][N];
}