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

        int and_result = 0;
        bool success = false;

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];

            if (i == 1) {
                and_result = arr[i];
            } else {
                and_result &= arr[i];
            }
        }

        for (int i = 1; i <= N; i++) {
            if (arr[i] == and_result) {
                success = true;
                break;
            }
        }

        if (!success) {
            cout << -1 << '\n';
            continue;
        }

        cout << 2 * N << '\n';

        for (int i = 1; i <= N; i++) {
            cout << arr[i] << ' ' << and_result << ' ';
        }
        cout << '\n';
    }
}