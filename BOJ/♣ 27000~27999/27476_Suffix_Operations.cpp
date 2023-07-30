#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll gap[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        ll sum = 0;

        ll prev;
        cin >> prev;

        for (int i = 1; i <= N - 1; i++) {
            ll cur;
            cin >> cur;

            gap[i] = cur - prev;
            sum += abs(gap[i]);

            prev = cur;
        }

        ll best_chance_score = max(abs(gap[1]), abs(gap[N - 1]));

        for (int i = 1; i <= N - 2; i++) {
            ll cur_chance_score = abs(gap[i]) + abs(gap[i + 1]) - abs(gap[i] + gap[i + 1]);
            best_chance_score = max(best_chance_score, cur_chance_score);
        }

        cout << sum - best_chance_score << '\n';
    }
}