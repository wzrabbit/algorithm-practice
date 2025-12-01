#include <algorithm>
#include <iostream>
#include <map>
typedef long long ll;
using namespace std;

ll arr[1000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, K;
    cin >> N >> K;

    ll sum = 0;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    if (sum % K != 0) {
        cout << "blobsad";
        return 0;
    }

    ll moves = 0;
    ll selected_count = 0;
    ll mid_index;
    map<ll, ll> index_map;

    for (int i = 1; i <= N; i++) {
        ll matched = min(K - selected_count, arr[i]);

        if (selected_count < (K + 1) / 2 &&
            selected_count + matched >= (K + 1) / 2) {
            mid_index = i;
        }

        selected_count += matched;
        arr[i] -= matched;
        index_map[i] = matched;

        if (selected_count == K) {
            for (auto it = index_map.begin(); it != index_map.end(); it++) {
                ll index = it->first;
                ll count = it->second;
                moves += abs(mid_index - index) * count;
            }

            index_map.clear();
            arr[i] %= K;
            selected_count = arr[i];
            index_map[i] = arr[i];
            arr[i] = 0;

            if (selected_count >= (K + 1) / 2) {
                mid_index = i;
            }
        }
    }

    cout << moves;
}
