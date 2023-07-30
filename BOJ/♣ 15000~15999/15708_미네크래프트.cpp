#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, T, P;
    cin >> N >> T >> P;

    priority_queue<int> pq;
    int total = 0;
    int limit = T;
    int best_stone_count = 0;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;
        pq.push(cur);
        total += cur;

        while (total > limit) {
            int popped = pq.top();
            pq.pop();
            total -= popped;
        }

        best_stone_count = max(best_stone_count, (int)pq.size());
        limit -= P;
        limit = max(0, limit);
    }

    cout << best_stone_count;
}