#include <iostream>
typedef long long ll;
using namespace std;

ll get_gcd(ll x, ll y) {
    if (x % y == 0) return y;
    return get_gcd(y, x % y);
}

ll get_square_count(ll num) {
    ll start = 1;
    ll end = 1073741824;
    ll mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (mid * mid <= num) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return end;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll A, B;
    cin >> A >> B;

    ll up = get_square_count(B) - get_square_count(A);
    ll down = B - A;
    ll gcd = get_gcd(up, down);

    if (up == 0) {
        cout << 0;
    } else {
        cout << up / gcd << '/' << down / gcd;
    }
}
