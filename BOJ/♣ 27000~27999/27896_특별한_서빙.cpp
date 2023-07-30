#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    int anger = 0;
    priority_queue<int> pq;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        pq.push(cur);
        anger += cur;

        while (anger >= M) {
            anger -= pq.top() * 2;
            pq.pop();
        }
    }

    cout << N - pq.size();
}