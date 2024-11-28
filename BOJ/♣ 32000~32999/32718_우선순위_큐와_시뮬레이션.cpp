#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll arr[200001];
ll A, N, K, Q;

ll get_query_answer(int cur_A) {
    A = (A + cur_A) % K;

    int start = 1;
    int end = N;
    int mid;
    ll cur_find = K - A - 1;

    while (start <= end) {
        mid = (start + end) / 2;

        if (arr[mid] <= cur_find) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    if (end == 0) {
        return (arr[N] + A) % K;
    }

    return (arr[end] + A) % K;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        arr[i] %= K;
    }

    sort(arr + 1, arr + N + 1);

    for (int i = 1; i <= Q; i++) {
        ll cur_A;
        cin >> cur_A;
        cout << get_query_answer(cur_A) << ' ';
    }
}
