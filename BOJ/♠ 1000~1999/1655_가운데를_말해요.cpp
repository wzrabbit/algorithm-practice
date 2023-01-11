#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    priority_queue<int> low_pq;
    priority_queue<int, vector<int>, greater<int>> high_pq;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;
        low_pq.push(cur);

        if (i % 2 == 1) {
            if (!high_pq.empty() && low_pq.top() > high_pq.top()) {
                int low_popped = low_pq.top();
                int high_popped = high_pq.top();
                low_pq.pop();
                high_pq.pop();

                low_pq.push(high_popped);
                high_pq.push(low_popped);
            }
        } else {
            int low_popped = low_pq.top();
            low_pq.pop();

            high_pq.push(low_popped);
        }

        cout << low_pq.top() << '\n';
    }
}