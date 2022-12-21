#include <algorithm>
#include <initializer_list>
#include <iostream>
#define INF -1000000000
using namespace std;

int arr[100001];
int dp[2][100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int best = arr[1];
    dp[0][0] = dp[1][0] = INF;

    for (int i = 1; i <= N; i++) {
        dp[0][i] = max(arr[i], dp[0][i - 1] + arr[i]);
        dp[1][i] = max(dp[0][i - 1], dp[1][i - 1] + arr[i]);
        best = max({best, dp[0][i], dp[1][i]});
    }

    cout << best;
}