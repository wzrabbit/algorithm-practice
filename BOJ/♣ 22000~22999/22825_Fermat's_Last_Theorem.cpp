#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    while (true) {
        ll n;
        cin >> n;

        if (n == 0) {
            break;
        }

        ll best = n * n * n;

        for (ll x = 1; x <= 1111; x++) {
            for (ll y = 1; y <= 1111; y++) {
                ll calc = n * n * n - x * x * x - y * y * y;

                if (calc >= 0) {
                    best = min(best, calc);
                }
            }
        }

        cout << best << '\n';
    }
}