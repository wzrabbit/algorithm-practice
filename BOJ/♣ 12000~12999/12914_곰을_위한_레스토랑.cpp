#include <algorithm>
#include <iostream>
#include <set>
#define INF 2'000'000'000
using namespace std;

set<int> bears;
int N, gap;

bool is_insert_possible(int pos) {
    auto right_bear_pos = lower_bound(bears.begin(), bears.end(), pos);
    auto left_bear_pos = right_bear_pos;
    left_bear_pos--;

    return abs(*right_bear_pos - pos) >= gap && abs(*left_bear_pos - pos) >= gap;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> gap;
    bears.insert(-INF);
    bears.insert(INF);

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        if (is_insert_possible(cur)) {
            bears.insert(cur);
            cout << cur << ' ';
            continue;
        }

        for (auto it = bears.begin(); it != bears.end(); it++) {
            int it_cur = *it + gap;

            if (it_cur < cur) continue;
            if (*it == -INF || *it == INF) continue;

            auto right_bear_pos = it;
            auto left_bear_pos = it;

            right_bear_pos--;
            left_bear_pos++;

            if (abs(*right_bear_pos - it_cur) >= gap && abs(*left_bear_pos - it_cur) >= gap) {
                cout << it_cur << ' ';
                bears.insert(it_cur);
                break;
            }
        }
    }
}