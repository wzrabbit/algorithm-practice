#include <algorithm>
#include <iostream>
#define MOD 1'000'000'007
typedef long long ll;
using namespace std;

struct Pos {
    int r, c;
};

bool operator<(const Pos& a, const Pos& b) {
    if (a.r != b.r) {
        return a.r < b.r;
    }

    return a.c < b.c;
}

ll factorial[2000001];
ll dp[22][22];
Pos bombs[22];
int R, C, K;

ll get_inverse(ll x, ll y) {
    if (y == 1) {
        return x % MOD;
    }

    ll prev = get_inverse(x, y / 2);

    if (y % 2 == 1) {
        return prev * prev % MOD * x % MOD;
    } else {
        return prev * prev % MOD;
    }
}

void precalculate() {
    factorial[0] = 1;

    for (ll i = 1; i <= 2000000; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
}

void make_dp() {
    for (int i = 0; i <= K; i++) {
        for (int j = i + 1; j <= K + 1; j++) {
            ll r_diff = bombs[j].r - bombs[i].r;
            ll c_diff = bombs[j].c - bombs[i].c;

            if (r_diff < 0 || c_diff < 0) {
                dp[i][j] = 0;
                continue;
            }

            dp[i][j] = factorial[r_diff + c_diff] *
                       get_inverse(factorial[r_diff], MOD - 2) %
                       MOD *
                       get_inverse(factorial[c_diff], MOD - 2) %
                       MOD;
        }
    }
}

ll get_calculated_counts(ll bit) {
    int before_no = 0;
    ll counts = 1;
    ll one_count = 1;

    for (int i = 1; i <= K + 1; i++) {
        if ((bit & (1 << (K + 1 - i))) == 0) {
            continue;
        }

        int after_no = i;

        counts = (counts * dp[before_no][after_no]) % MOD;
        one_count += 1;
        before_no = after_no;
    }

    if (one_count % 2 == 1) {
        return MOD - counts;
    }

    return counts;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> K;

    precalculate();

    for (int i = 1; i <= K; i++) {
        cin >> bombs[i].r >> bombs[i].c;
    }

    bombs[0] = {0, 0};
    bombs[K + 1] = {R, C};

    sort(bombs + 1, bombs + K + 2);

    make_dp();

    ll counts = 0;

    for (ll i = 0; i < (1 << K); i++) {
        ll cur_bit = (i << 1) | 1;
        counts = (counts + get_calculated_counts(cur_bit)) % MOD;
    }

    cout << counts;
}
