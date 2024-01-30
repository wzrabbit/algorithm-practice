#include <iostream>
typedef long long ll;
using namespace std;

ll get_pow(ll x, ll y, ll MOD) {
    if (y == 0) {
        return 1;
    }

    ll result = get_pow(x, y / 2, MOD);

    if (y % 2 == 0) {
        return result * result % MOD;
    }

    return result * result % MOD * x % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, MOD;
    cin >> N >> MOD;

    ll result = 0;

    for (int i = 2; i <= N + 1; i++) {
        ll cur;
        cin >> cur;

        result = (result + get_pow(cur, i, MOD)) % MOD;
    }

    cout << result;
}
