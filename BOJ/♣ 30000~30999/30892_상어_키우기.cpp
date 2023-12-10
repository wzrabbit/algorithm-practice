#include <algorithm>
#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, K, T;
    cin >> N >> K >> T;

    vector<ll> values;
    priority_queue<ll> pq;

    for (int i = 1; i <= N; i++) {
        ll cur;
        cin >> cur;

        values.push_back(cur);
    }

    sort(values.begin(), values.end());
    int index = 0;

    for (int i = 1; i <= K; i++) {
        while (index < N && values[index] < T) {
            pq.push(values[index++]);
        }

        if (pq.empty()) {
            break;
        }

        ll cur = pq.top();
        pq.pop();

        T += cur;
    }

    cout << T;
}