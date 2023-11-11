#include <iostream>
typedef long long ll;
using namespace std;

ll get_gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    }

    return get_gcd(b, a % b);
}

ll get_lcm(ll a, ll b) {
    return a * b / get_gcd(a, b);
}

ll fractions[51][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> fractions[i][0] >> fractions[i][1];
    }

    ll lcm = fractions[1][1];

    for (int i = 2; i <= N; i++) {
        lcm = get_lcm(lcm, fractions[i][1]);
    }

    ll gcd = fractions[1][0] * lcm / fractions[1][1];

    for (int i = 2; i <= N; i++) {
        gcd = get_gcd(gcd, fractions[i][0] * lcm / fractions[i][1]);
    }

    ll final_gcd = get_gcd(gcd, lcm);

    cout << gcd / final_gcd << ' ' << lcm / final_gcd;
}