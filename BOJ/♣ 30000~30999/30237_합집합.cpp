#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<int> sets[51];

int get_combined_set_size(int R, int ban) {
    set<int> S;

    for (int r = 1; r <= R; r++) {
        if (sets[r].find(ban) != sets[r].end()) {
            continue;
        }

        for (auto it = sets[r].begin(); it != sets[r].end(); it++) {
            S.insert(*it);
        }
    }

    return S.size();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int R;
        cin >> R;

        for (int r = 1; r <= R; r++) {
            int C;
            cin >> C;

            sets[r].clear();

            for (int c = 0; c < C; c++) {
                int cur;
                cin >> cur;

                sets[r].insert(cur);
            }
        }

        int all_size = get_combined_set_size(R, -1);
        int best_size = 0;

        for (int i = 1; i <= 50; i++) {
            int cur = get_combined_set_size(R, i);

            if (cur < all_size) {
                best_size = max(best_size, cur);
            }
        }

        cout << best_size << '\n';
    }
}
