#include <algorithm>
#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

priority_queue<ll, vector<ll>, greater<ll>> pq;
int zero_count = 0;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        ll cur;
        cin >> cur;

        pq.push(cur);
    }

    while (Q--) {
        ll x, y;
        cin >> x >> y;

        if (y == 1) continue;

        if (y == 0) {
            while (!pq.empty() && pq.top() <= x) {
                pq.pop();
                zero_count += 1;
            }

            continue;
        }

        vector<ll> popped;

        while (!pq.empty() && pq.top() <= x) {
            ll cur = pq.top();
            pq.pop();
            popped.push_back(cur);
        }

        for (size_t i = 0; i < popped.size(); i++) {
            popped[i] *= y;
            pq.push(popped[i]);
        }
    }

    for (int i = 1; i <= zero_count; i++) {
        cout << 0 << ' ';
    }

    while (!pq.empty()) {
        ll cur = pq.top();
        pq.pop();
        cout << cur << ' ';
    }
}