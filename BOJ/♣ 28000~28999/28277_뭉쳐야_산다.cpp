#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

set<int> sets[500001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        int set_size;
        cin >> set_size;

        for (int j = 1; j <= set_size; j++) {
            int cur;
            cin >> cur;

            sets[i].insert(cur);
        }
    }

    while (Q--) {
        int query;
        cin >> query;

        if (query == 1) {
            int a, b;
            cin >> a >> b;

            if (sets[a].size() < sets[b].size()) {
                swap(sets[a], sets[b]);
            }

            for (auto it = sets[b].begin(); it != sets[b].end(); it++) {
                sets[a].insert(*it);
            }

            sets[b].clear();

            continue;
        }

        int target;
        cin >> target;

        cout << sets[target].size() << '\n';
    }
}