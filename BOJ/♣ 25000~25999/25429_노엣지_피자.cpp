#include <algorithm>
#include <iostream>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, S, Q;
    cin >> N >> S >> Q;

    map<ll, ll> checker;
    map<ll, ll> db;
    ll total = 0;
    ll conflict = 0;

    while (Q--) {
        ll q, a, b;
        cin >> q;

        if (q == 1) {
            cin >> a >> b;
            a--;

            if (db.count(a) == 0 || db[a] == 0) {
                total += b;
                if (checker.count(a % S) == 0)
                    checker[a % S] = 1;
                else
                    checker[a % S]++;
                db[a] = b;

                if (checker[a % S] == 2)
                    conflict++;
            } else {
                total += b - db[a];
                db[a] = b;
            }
        } else {
            cin >> a;
            a--;
            checker[a % S]--;
            total -= db[a];
            db[a] = 0;

            if (checker[a % S] == 1)
                conflict--;
        }

        if (conflict > 0)
            cout << "NO\n";
        else
            cout << "YES " << total << '\n';
    }
}