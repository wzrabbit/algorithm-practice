#include <algorithm>
#include <iostream>
using namespace std;

int arr[1000001];

bool is_square(int num) {
    int start = 1;
    int end = 1500;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (mid * mid < num) {
            start = mid + 1;
        } else if (mid * mid > num) {
            end = mid - 1;
        } else {
            return true;
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            arr[i] = i;
        }

        for (int i = 2; i <= N - 1; i++) {
            if (is_square(arr[i] + arr[i + 1])) {
                swap(arr[i - 1], arr[i]);
            }
        }

        for (int i = 1; i <= N; i++) {
            cout << arr[i] << ' ';
        }

        cout << '\n';
    }
}
