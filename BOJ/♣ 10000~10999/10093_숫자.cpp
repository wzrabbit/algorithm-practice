#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll start, end;
    cin >> start >> end;

    if (start > end) {
        swap(start, end);
    }

    cout << max(0ll, end - start - 1) << '\n';

    for (ll i = start + 1; i < end; i++) {
        cout << i << ' ';
    }
}
