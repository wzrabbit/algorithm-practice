#include <algorithm>
#include <iostream>
#include <set>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        ll N, K;
        cin >> N >> K;

        ll need = -K;
        ll ship = K;
        ll mobil_count = 0;
        bool success = true;
        multiset<ll, greater<ll>> planets;

        for (int i = 1; i <= N; i++) {
            ll cur;
            cin >> cur;

            need += cur;
            planets.insert(cur);
        }

        while (true) {
            if (need <= 0) {
                break;
            }

            auto it = planets.lower_bound(ship);

            if (it == planets.end()) {
                success = false;
                break;
            }

            mobil_count += 1;
            ship += *it;
            need -= *it * 2;
            planets.erase(it);
        }

        if (success) {
            cout << mobil_count << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}