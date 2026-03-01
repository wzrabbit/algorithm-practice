#include <iostream>
#define MOD 1'000'000'007
typedef long long ll;
using namespace std;

// https://www.acmicpc.net/source/46108150
ll get_inverse(ll x, ll y) {
    if (y == 1) return x % MOD;

    ll prev = get_inverse(x, y / 2);

    if (y % 2 == 1)
        return prev * prev % MOD * x % MOD;
    else
        return prev * prev % MOD;
}

ll dp[1048576];
ll degree[20];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        ll cur;
        cin >> cur;
        degree[i] = cur * cur;
    }

    dp[(1 << N) - 1] = 1;

    for (int i = (1 << N) - 1; i >= 1; i--) {
        ll total = 0;

        for (int j = 0; j < N; j++) {
            if ((i & (1 << j)) != 0) {
                total += degree[j];
            }
        }

        ll inv = get_inverse(total, MOD - 2);

        for (int j = 0; j < N; j++) {
            if ((i & (1 << j)) == 0) {
                continue;
            }

            dp[i & ~(1 << j)] =
                (dp[i & ~(1 << j)] + (dp[i] * degree[j]) % MOD * inv % MOD) %
                MOD;
        }
    }

    ll answer = 0;

    for (int i = 0; i < (1 << N); i++) {
        if (i & 1) {
            continue;
        }

        ll gacha_count = 0;

        for (int j = 0; j < N; j++) {
            if ((i & (1 << j)) == 0) {
                gacha_count += 1;
            }
        }

        if (gacha_count == M) {
            answer = (answer + dp[i]) % MOD;
        }
    }

    cout << answer;
}
