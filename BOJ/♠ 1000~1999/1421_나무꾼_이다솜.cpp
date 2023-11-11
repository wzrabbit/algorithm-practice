#include <iostream>
typedef long long ll;
using namespace std;

ll trees[51];
ll N, C, W;

ll get_profit(ll unit) {
    ll total_profit = 0;

    for (int i = 1; i <= N; i++) {
        if (trees[i] < unit) {
            continue;
        }

        ll wood_count = trees[i] / unit;
        ll current_profit = wood_count * unit * W;
        ll cut_count = wood_count;

        if (trees[i] % unit == 0) {
            cut_count -= 1;
        }

        current_profit -= cut_count * C;
        total_profit += max(0LL, current_profit);
    }

    return total_profit;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> C >> W;

    for (int i = 1; i <= N; i++) {
        cin >> trees[i];
    }

    ll best_profit = 0;

    for (int i = 1; i <= 10000; i++) {
        best_profit = max(best_profit, get_profit(i));
    }

    cout << best_profit;
}
