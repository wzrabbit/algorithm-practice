#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll arr[100001];
ll dp[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = arr[2];

    for (int i = 3; i <= N; i++) {
        dp[i] = min(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
    }

    cout << min(dp[N - 1], dp[N]);
}
