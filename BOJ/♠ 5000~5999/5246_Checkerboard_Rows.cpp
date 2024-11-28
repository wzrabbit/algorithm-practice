#include <algorithm>
#include <iostream>
using namespace std;

int counts[9];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        fill(counts + 1, counts + 9, 0);

        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            int _, r;
            cin >> _ >> r;

            counts[r] += 1;
        }

        int best_count = 0;

        for (int i = 1; i <= 8; i++) {
            best_count = max(best_count, counts[i]);
        }

        cout << best_count << '\n';
    }
}