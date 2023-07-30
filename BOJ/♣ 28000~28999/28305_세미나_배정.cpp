#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
typedef long long ll;
using namespace std;

ll arr[200001];
queue<ll> q;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, W;
    cin >> N >> W;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + N + 1);

    ll start = 1;
    ll end = N;
    ll mid;

    while (start <= end) {
        mid = (start + end) / 2;

        priority_queue<ll, vector<ll>, greater<ll>> pq;
        bool success = true;

        for (int i = 1; i <= mid; i++) {
            pq.push(0);
        }

        for (int i = 1; i <= N; i++) {
            if (pq.top() >= arr[i]) {
                success = false;
                break;
            }

            int cur = pq.top();
            pq.pop();
            pq.push(max(arr[i], cur + W));
        }

        if (success) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << start;
}