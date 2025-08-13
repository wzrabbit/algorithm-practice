#include <iostream>
typedef long long ll;
using namespace std;

struct Fraction {
    ll u, d;
};

ll down_values[500001];
ll up_values[500001];

ll get_gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    }

    return get_gcd(b, a % b);
}

int compare_fraction(Fraction a, Fraction b) {
    ll a_value = a.u * b.d;
    ll b_value = b.u * a.d;

    if (a_value > b_value) {
        return 1;
    }

    if (a_value == b_value) {
        return 0;
    }

    return -1;
}

Fraction reduce_fraction(Fraction f) {
    ll gcd = get_gcd(f.u, f.d);
    return {f.u / gcd, f.d / gcd};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> down_values[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> up_values[i];
    }

    Fraction max_fraction = {0, 1};

    for (int i = 1; i <= N; i++) {
        Fraction fraction = {up_values[i], down_values[i]};
        int compare_result = compare_fraction(fraction, max_fraction);

        if (compare_result == 1) {
            max_fraction = reduce_fraction(fraction);
        }
    }

    ll max_lr_gap = 0;
    ll cur_lr_gap = 0;

    for (int i = 1; i <= N; i++) {
        Fraction cur_fraction = {up_values[i], down_values[i]};

        if (compare_fraction(cur_fraction, max_fraction) == 0) {
            cur_lr_gap += 1;
        } else {
            cur_lr_gap = 0;
        }

        max_lr_gap = max(cur_lr_gap, max_lr_gap);
    }

    cout << max_fraction.u << ' ' << max_fraction.d << '\n';
    cout << max_lr_gap;
}
