#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll arr[16];
ll dp[1 << 16][16];

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    };

    for (int i = 0; i < N; i++) {
        dp[1 << i][i] = 1;
    }

    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (abs(arr[j] - arr[k]) <= K) {
                    continue;
                }

                if ((i & (1 << k)) == 0) {
                    dp[i | (1 << k)][k] += dp[i][j];
                }
            }
        }
    }

    ll answer = 0;
    ll full_bit = 0;

    for (int i = 0; i < N; i++) {
        full_bit |= (1 << i);
    }

    for (int i = 0; i < N; i++) {
        answer += dp[full_bit][i];
    }

    cout << answer;
}
