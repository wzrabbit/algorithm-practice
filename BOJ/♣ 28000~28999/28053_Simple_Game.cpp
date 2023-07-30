#include <iostream>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    ll N, A, B;
    cin >> N >> A >> B;

    if (gcd(A, A + B) > 1) {
        cout << "No";
        return 0;
    }

    ll cur = A;
    cout << "Yes\n";

    for (int i = 1; i <= N; i++) {
        cout << cur << ' ' << cur + B << '\n';
        cur += B * 2;
    }
}