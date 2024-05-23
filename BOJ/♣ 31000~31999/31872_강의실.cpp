#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll arr[100002];
ll dist[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    arr[N + 1] = 0;

    sort(arr + 1, arr + N + 2);

    for (int i = 1; i <= N; i++) {
        dist[i] = arr[i + 1] - arr[i];
    }

    sort(dist + 1, dist + N + 1);

    ll total_dist = 0;

    for (int i = 1; i <= N - K; i++) {
        total_dist += dist[i];
    }

    cout << total_dist << '\n';
}
