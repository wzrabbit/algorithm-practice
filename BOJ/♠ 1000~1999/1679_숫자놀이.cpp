#include <algorithm>
#include <iostream>
#define INF 1'000'000'000
using namespace std;

int dp[50002];
int arr[51];

int main() {
    int N, K;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    fill(dp + 1, dp + 50002, INF);

    for (int i = 1; i <= 50000; i++) {
        for (int j = 1; j <= N; j++) {
            if (i - arr[j] >= 0) {
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            }
        }
    }

    cin >> K;

    for (int i = 1; i <= 50001; i++) {
        if (dp[i] <= K) continue;

        if (i % 2 == 0) {
            cout << "holsoon win at " << i;
        } else {
            cout << "jjaksoon win at " << i;
        }

        break;
    }
}
