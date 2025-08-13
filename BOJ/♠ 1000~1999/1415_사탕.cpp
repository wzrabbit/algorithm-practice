#include <iostream>
#include <map>
typedef long long ll;
using namespace std;

bool is_sieve[500001];
ll dp[500001];
map<ll, ll> candy_count;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    fill(is_sieve + 2, is_sieve + 500001, true);

    for (int i = 2; i * i <= 500000; i++) {
        if (is_sieve[i]) {
            for (int j = i * i; j <= 500000; j += i) {
                is_sieve[j] = false;
            }
        }
    }

    int N;
    cin >> N;

    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;
        candy_count[cur] += 1;
    }

    for (const auto& [cur, count] : candy_count) {
        if (cur == 0) continue;

        for (int j = 500000; j >= 0; j--) {
            for (int k = 1; k <= count; k++) {
                if (j + cur * k > 500000) break;
                dp[j + cur * k] += dp[j];
            }
        }
    }

    ll answer = 0;

    for (int i = 2; i <= 500000; i++) {
        if (is_sieve[i]) {
            answer += dp[i];
        }
    }

    answer *= candy_count[0] + 1;

    cout << answer;
}
