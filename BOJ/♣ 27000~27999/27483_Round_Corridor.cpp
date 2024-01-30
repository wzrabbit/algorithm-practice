#include <iostream>
typedef long long ll;
using namespace std;

ll get_gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    }

    return get_gcd(b, a % b);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, M, Q;
    cin >> N >> M >> Q;

    ll gcd = get_gcd(N, M);

    while (Q--) {
        ll sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        ll s_group_no = 0;
        ll e_group_no = 0;

        if (sx == 1) {
            s_group_no = (sy - 1) / (N / gcd);
        } else {
            s_group_no = (sy - 1) / (M / gcd);
        }

        if (ex == 1) {
            e_group_no = (ey - 1) / (N / gcd);
        } else {
            e_group_no = (ey - 1) / (M / gcd);
        }

        if (s_group_no == e_group_no) {
            cout << "YEs\n";
        } else {
            cout << "nO\n";
        }
    }
}