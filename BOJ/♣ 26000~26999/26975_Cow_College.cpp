#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll price[1000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        ll cur;
        cin >> cur;

        price[cur] += 1;
    }

    ll best_profit = 0;
    ll best_price = 0;
    ll cow_count = N;

    for (ll i = 1; i <= 1000000; i++) {
        if (price[i] == 0) continue;

        if (best_profit < i * cow_count) {
            best_profit = i * cow_count;
            best_price = i;
        }

        cow_count -= price[i];
    }

    cout << best_profit << ' ' << best_price;
}