#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll arr[100001];
ll N, M, K;

bool is_possible(int pos) {
    ll total_time = 0;

    for (int i = pos; i >= 1; i -= K) {
        total_time += arr[i];
    }

    return total_time <= M;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + N + 1);

    int start = 1;
    int end = N;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (is_possible(mid)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << end;
}