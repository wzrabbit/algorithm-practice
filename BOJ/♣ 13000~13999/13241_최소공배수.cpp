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

int main() {
    ll a, b;
    cin >> a >> b;

    cout << get_lcm(a, b);
}
