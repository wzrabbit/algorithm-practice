#include <algorithm>
#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        priority_queue<ll, vector<ll>, greater<ll>> pq;

        for (int i = 1; i <= N; i++) {
            ll cur;
            cin >> cur;

            pq.push(cur);
        }

        ll total_cost = 0;

        while (pq.size() >= 2) {
            ll first = pq.top();
            pq.pop();
            ll second = pq.top();
            pq.pop();

            ll cur_cost = first + second;
            total_cost += cur_cost;
            pq.push(cur_cost);
        }

        cout << total_cost << '\n';
    }
}