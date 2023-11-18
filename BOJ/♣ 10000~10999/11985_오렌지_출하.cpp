#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll dp[20001];
ll arr[20001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];

        ll minimum = arr[i];
        ll maximum = arr[i];
        dp[i] = dp[i - 1] + K;

        for (int j = 1; j <= min((ll)i - 1, M - 1); j++) {
            minimum = min(minimum, arr[i - j]);
            maximum = max(maximum, arr[i - j]);

            dp[i] = min(dp[i], dp[i - j - 1] + (maximum - minimum) * (j + 1) + K);
        }
    }

    cout << dp[N];
}