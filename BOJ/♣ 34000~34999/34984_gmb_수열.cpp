#include <iostream>
#define MOD 1'000'000'007
typedef long long ll;
using namespace std;

ll arr[200001];
ll number_count[300];
ll dp[300][300];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    ll answer = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 300; j++) {
            int target = j + arr[i];
            if (target < 0 || target >= 300) continue;

            answer = (answer + dp[target][j]) % MOD;
            dp[j][arr[i]] = (dp[j][arr[i]] + dp[target][j]) % MOD;
        }

        for (int j = 0; j < 300; j++) {
            dp[j][arr[i]] = (dp[j][arr[i]] + number_count[j]) % MOD;
        }

        number_count[arr[i]] += 1;
    }

    cout << answer;
}
