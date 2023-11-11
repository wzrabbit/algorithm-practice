#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll arr[10001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    ll dist_total = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist_total += abs(arr[i] - arr[j]);
        }
    }

    cout << dist_total;
}