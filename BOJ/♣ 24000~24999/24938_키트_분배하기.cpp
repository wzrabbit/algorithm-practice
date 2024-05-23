#include <iostream>
typedef long long ll;
using namespace std;

ll arr[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    ll average = 0;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        average += arr[i];
    }

    average /= N;

    ll plus_storage = 0;
    ll minus_storage = 0;
    ll cost = 0;

    for (int i = 1; i <= N; i++) {
        cost += plus_storage + minus_storage;

        ll diff = arr[i] - average;

        if (diff > 0) {
            ll matched = min(minus_storage, diff);
            arr[i] -= matched;
            minus_storage -= matched;
        }

        if (diff < 0) {
            ll matched = min(plus_storage, -diff);
            arr[i] += matched;
            plus_storage -= matched;
        }

        ll updated_diff = arr[i] - average;

        if (updated_diff > 0) {
            plus_storage += updated_diff;
        } else {
            minus_storage += -updated_diff;
        }
    }

    cout << cost;
}
