#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll arr[100000];

bool check(ll interval, int N) {
    ll one = 0;
    ll other = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] <= interval)
            one++;
        else {
            other += (arr[i] % interval > 0 ? arr[i] / interval + 1 : arr[i] / interval) - 2;
        }
    }
    other++;

    if (one >= other)
        return true;
    else
        return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    ll start = 1;
    ll end = 1000000000;
    ll mid;

    while (start <= end) {
        mid = (start + end) / 2;
        if (check(mid, N))
            end = mid - 1;
        else
            start = mid + 1;
    }

    cout << start;
}