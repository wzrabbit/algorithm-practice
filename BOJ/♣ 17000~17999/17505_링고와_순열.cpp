#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

int is_used[314160];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, K;
    cin >> N >> K;

    for (int i = N; i >= 1; i--) {
        if (K == 0) break;

        int matched = min(K, ll(i - 1));
        K -= matched;
        is_used[matched + 1] = true;

        cout << matched + 1 << ' ';
    }

    for (int i = 1; i <= N; i++) {
        if (!is_used[i]) cout << i << ' ';
    }
}