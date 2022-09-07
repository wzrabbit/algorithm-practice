#include <iostream>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        ll conqueror = -1;
        map<ll, int> db;

        for (int i = 0; i < N; i++) {
            ll x;
            cin >> x;
            if (db.count(x) == 0)
                db[x] = 1;
            else
                db[x]++;

            if (db[x] > N / 2)
                conqueror = x;
        }

        if (conqueror == -1)
            cout << "SYJKGW\n";
        else
            cout << conqueror << '\n';
    }
}