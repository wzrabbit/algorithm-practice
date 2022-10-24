#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    while (true) {
        ll x;
        cin >> x;

        if (x == 0) break;
        cout << (x * (x + 1) * (2 * x + 4)) / 12 << '\n';
    }
}