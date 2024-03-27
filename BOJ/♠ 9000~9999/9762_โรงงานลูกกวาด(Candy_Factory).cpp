#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

int arr[1002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int i = N / 2 + 1; i <= N; i++) {
            cin >> arr[i];
        }

        for (int i = N / 2; i >= 1; i--) {
            int matched = min(arr[i * 2], arr[i * 2 + 1]);
            arr[i] = matched;
            arr[i * 2] -= matched;
            arr[i * 2 + 1] -= matched;
        }

        int total = 0;

        for (int i = 1; i <= N; i++) {
            total += arr[i];
        }

        cout << total << '\n';
    }
}
