#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll prefix[200001];
int N, Q;

ll get_range_sum(ll start, ll end) {
    if (start <= end) {
        return prefix[end] - prefix[start - 1];
    }

    return prefix[N] + prefix[end] - prefix[start - 1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        ll cur;
        cin >> cur;

        prefix[i] = prefix[i - 1] + cur;
    }

    ll start = 0;

    while (Q--) {
        ll q;
        cin >> q;

        if (q == 1) {
            ll x;
            cin >> x;

            start = (start + N - x) % N;
            continue;
        }

        if (q == 2) {
            ll x;
            cin >> x;

            start = (start + x) % N;
            continue;
        }

        ll left, right;
        cin >> left >> right;

        left = (left - 1 + start) % N + 1;
        right = (right - 1 + start) % N + 1;

        cout << get_range_sum(left, right) << '\n';
    }
}
