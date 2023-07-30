#include <algorithm>
#include <iostream>
using namespace std;

int arr[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + N + 1);

    int sum = 0;
    int best = 0;
    int cur = 0;

    for (int i = 1; i <= N; i++) {
        sum += arr[i];

        if (arr[i - 1] == arr[i]) {
            cur += arr[i];
        } else {
            cur = arr[i];
        }

        best = max(cur, best);
    }

    cout << sum + best << '\n';

    for (int i = 1; i <= N; i++) {
        cout << arr[i] << ' ';
    }
}