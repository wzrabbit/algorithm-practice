#include <iostream>
using namespace std;

int prices[13];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int money, best_before_index, best_after_index;
        cin >> money;
        int best_profit = 0;

        for (int i = 1; i <= 12; i++) {
            cin >> prices[i];
        }

        for (int i = 1; i <= 11; i++) {
            for (int j = i + 1; j <= 12; j++) {
                int buy_count = money / prices[i];
                int current_profit = buy_count * (prices[j] - prices[i]);

                if (current_profit > best_profit || (current_profit == best_profit && prices[i] < prices[best_before_index])) {
                    best_profit = current_profit;
                    best_before_index = i;
                    best_after_index = j;
                }
            }
        }

        cout << "Case #" << t << ": ";

        if (best_profit == 0) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << best_before_index << ' ' << best_after_index << ' ' << best_profit << '\n';
        }
    }
}