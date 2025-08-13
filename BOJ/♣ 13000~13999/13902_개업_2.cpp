#include <algorithm>
#include <iostream>
#define INF 100'000
using namespace std;

int arr[1001];
bool wok[10001];
int dp[10001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> arr[i];
        wok[arr[i]] = true;
    }

    for (int i = 1; i <= M - 1; i++) {
        for (int j = i + 1; j <= M; j++) {
            wok[min(10000, arr[i] + arr[j])] = true;
        }
    }

    fill(dp + 1, dp + N + 1, INF);

    for (int i = 1; i <= 10000; i++) {
        if (!wok[i]) {
            continue;
        }

        for (int j = i; j <= N; j++) {
            dp[j] = min(dp[j], dp[j - i] + 1);
        }
    }

    if (dp[N] == INF) {
        cout << -1;
    } else {
        cout << dp[N];
    }
}
