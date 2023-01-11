#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll get_parent(ll child, ll K) {
    if (child % K <= 1) {
        return child / K;
    }

    return child / K + 1;
}

ll get_dist(ll x, ll y, ll K) {
    ll dist = 0;

    if (K == 1) {
        return abs(x - y);
    }

    while (x != y) {
        if (x > y) {
            x = get_parent(x, K);
        } else {
            y = get_parent(y, K);
        }
        dist += 1;
    }

    return dist;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, K, Q;
    cin >> N >> K >> Q;

    while (Q--) {
        ll x, y;
        cin >> x >> y;

        cout << get_dist(x, y, K) << '\n';
    }
}