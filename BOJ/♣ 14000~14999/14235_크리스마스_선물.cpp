#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    priority_queue<int> pq;

    for (int i = 1; i <= N; i++) {
        int query;
        cin >> query;

        if (query == 0) {
            if (pq.empty()) {
                cout << -1 << '\n';
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }

            continue;
        }

        for (int i = 1; i <= query; i++) {
            int value;
            cin >> value;

            pq.emplace(value);
        }
    }
}