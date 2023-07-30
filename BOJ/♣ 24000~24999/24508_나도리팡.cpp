#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll arr[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, K, T;
    cin >> N >> K >> T;

    ll need_time = 0;
    ll sum = 0;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    if (sum % K != 0) {
        cout << "NO";
        return 0;
    }

    ll pang = sum / K;

    sort(arr + 1, arr + N + 1, greater<ll>());

    for (int i = 1; i <= N; i++) {
        if (i <= pang) {
            need_time += K - arr[i];
        } else {
            need_time += arr[i];
        }
    }

    need_time /= 2;

    if (need_time <= T) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
