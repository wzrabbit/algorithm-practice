#include <iostream>
using namespace std;

int arr[200005];
int dp[200005];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N + 3; i++) {
        dp[i] = dp[i - 1] + arr[i];

        if (i >= 3) {
            dp[i] = max(dp[i], dp[i - 3] + (arr[i - 2] + arr[i - 1] + arr[i]) * 2);
        }
    }

    cout << dp[N + 3];
}
