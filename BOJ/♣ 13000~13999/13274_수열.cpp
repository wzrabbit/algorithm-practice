#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

ll arr[100001];
int N, Q;

void perform_query(ll left, ll right, ll value) {
    vector<ll> inner;
    vector<ll> outer;

    for (int i = 1; i <= N; i++) {
        if (i >= left && i <= right) {
            inner.push_back(arr[i] + value);
        } else {
            outer.push_back(arr[i]);
        }
    }

    int inner_index = 0;
    int outer_index = 0;

    for (int i = 1; i <= N; i++) {
        if (inner_index == inner.size()) {
            arr[i] = outer[outer_index];
            outer_index += 1;
            continue;
        }

        if (outer_index == outer.size()) {
            arr[i] = inner[inner_index];
            inner_index += 1;
            continue;
        }

        if (inner[inner_index] < outer[outer_index]) {
            arr[i] = inner[inner_index];
            inner_index += 1;
            continue;
        }

        arr[i] = outer[outer_index];
        outer_index += 1;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + N + 1);

    while (Q--) {
        ll left, right, value;
        cin >> left >> right >> value;

        perform_query(left, right, value);
    }

    for (int i = 1; i <= N; i++) {
        cout << arr[i] << ' ';
    }
}
