#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll arr[1000001];
ll result[1000001];

int main() {
    cin.tie(0)->sync_with_stdio();

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + N + 1);

    ll l = N / 2;
    ll r = l + 1;

    for (int i = 1; i <= N / 2; i++) {
        result[l] = arr[i];
        result[r] = arr[N - i + 1];

        if (i % 2 == 0) {
            swap(result[l], result[r]);
        }

        l -= 1;
        r += 1;
    }

    ll sum = 0;

    for (int i = 2; i <= N / 2 * 2; i++) {
        sum += abs(result[i] - result[i - 1]);
    }

    if (N % 2 == 1) {
        sum += max(abs(result[1] - arr[N / 2 + 1]), abs(result[N - 1] - arr[N / 2 + 1]));
    }

    cout << sum;
}
