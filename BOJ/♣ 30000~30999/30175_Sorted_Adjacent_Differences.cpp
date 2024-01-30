#include <algorithm>
#include <iostream>
using namespace std;

int arr[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        sort(arr + 1, arr + N + 1);

        int pos = (N + 2) / 2;

        for (int i = 1; i <= N; i++) {
            cout << arr[pos] << ' ';

            if (i % 2 == 1) {
                pos -= i;
            } else {
                pos += i;
            }
        }

        cout << '\n';
    }
}