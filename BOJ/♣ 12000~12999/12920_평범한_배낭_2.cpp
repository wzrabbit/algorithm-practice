#include <iostream>
typedef long long ll;
using namespace std;

ll dp[10001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        ll weight, happiness, things_count;
        cin >> weight >> happiness >> things_count;

        while (things_count > 0) {
            ll cur_things_count = things_count - things_count / 2;
            things_count /= 2;

            ll cur_weight = weight * cur_things_count;
            ll cur_happiness = happiness * cur_things_count;

            for (ll k = M - cur_weight; k >= 0; k--) {
                if (dp[k] == 0 && k != 0) {
                    continue;
                }

                dp[k + cur_weight] = max(dp[k + cur_weight], dp[k] + cur_happiness);
            }
        }
    }

    ll best_happiness = 0;

    for (int i = 1; i <= M; i++) {
        best_happiness = max(best_happiness, dp[i]);
    }

    cout << best_happiness;
}
