#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll cards[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            cin >> cards[i];
        }

        ll odd_sum = 0;
        ll even_remain_sum = 0;
        ll best_score = 0;

        for (int i = 1; i <= N; i += 2) {
            odd_sum += max(cards[i], 0ll);
        }

        for (int i = 2; i <= N; i += 2) {
            even_remain_sum += max(cards[i], 0ll);
        }

        for (int i = 1; i <= N; i++) {
            ll eliminate_penalty = 0;

            if (i % 2 == 0) {
                even_remain_sum -= max(cards[i], 0ll);
            }

            if (i % 2 == 1) {
                eliminate_penalty = max(-cards[i], 0ll);
            }

            best_score = max(best_score, odd_sum + even_remain_sum - eliminate_penalty);
        }

        cout << best_score << '\n';
    }
}
