#include <iostream>
#define MOD 1'000'000'007
typedef long long ll;
using namespace std;

ll arr[500001];
ll prefix[500001];
ll dp[500001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;
    N += 1;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        prefix[i] = (prefix[i - 1] * arr[i]) % MOD;
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = (dp[i - 1] + 1) * arr[i] % MOD;
    }

    ll answer = 0;

    for (int i = 1; i <= N; i++) {
        answer = (answer + dp[i]) % MOD;
    }

    cout << answer;
}
