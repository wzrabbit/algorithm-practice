#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll arr[500001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    ll start = 0;
    ll end = 2'000'000'000'000;
    ll mid;

    while (start <= end) {
        mid = (start + end) / 2;
        ll sum = 0;

        for (int i = 1; i <= N; i++) {
            sum += max(0ll, arr[i] - mid);
        }

        if (sum <= K) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << start;
}