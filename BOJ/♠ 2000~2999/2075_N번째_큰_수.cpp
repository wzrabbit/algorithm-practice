#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int cur;
            cin >> cur;

            pq.push(cur);
        }

        while (pq.size() > N) {
            pq.pop();
        }
    }

    cout << pq.top();
}
