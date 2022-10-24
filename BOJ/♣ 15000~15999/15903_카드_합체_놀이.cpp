#include <algorithm>
#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    for (int i = 0; i < M; i++) {
        ll x, y;
        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();

        pq.push(x + y);
        pq.push(x + y);
    }

    ll score = 0;
    while (pq.size()) {
        score += pq.top();
        pq.pop();
    }

    cout << score;
}