#include <iostream>
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;

ll factorial[2001];

ll get_inverse(ll x, ll y) {
    if (y == 1) return x % MOD;

    ll prev = get_inverse(x, y / 2);

    if (y % 2 == 1)
        return prev * prev % MOD * x % MOD;
    else
        return prev * prev % MOD;
}

void make_factorial() {
    factorial[0] = 1;
    for (int i = 1; i <= 2000; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    make_factorial();

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        ll answer = 1;
        ll books = N;
        bool is_all_one = true;

        for (int i = 1; i <= N; i++) {
            int cur;
            cin >> cur;

            if (cur != 1) {
                is_all_one = false;
            }

            if (cur == 0) {
                continue;
            }

            answer = answer * factorial[books] % MOD *
                     get_inverse(factorial[books - cur], MOD - 2) % MOD *
                     get_inverse(factorial[cur], MOD - 2) % MOD;

            books -= cur;
        }

        if (is_all_one) {
            cout << 1 << '\n';
        } else {
            cout << answer << '\n';
        }
    }
}
