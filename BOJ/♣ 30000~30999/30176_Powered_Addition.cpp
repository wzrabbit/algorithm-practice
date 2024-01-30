#include <algorithm>
#include <iostream>
#define INF 1'000'000'001
using namespace std;

int arr[100001];
int required[100001];

int get_bit_size(int num) {
    int bit_size = 0;

    while (num > 0) {
        num /= 2;
        bit_size += 1;
    }

    return bit_size;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        required[0] = -INF;

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            required[i] = max(required[i - 1], arr[i]);
        }

        int worst_seconds = 0;

        for (int i = 1; i <= N; i++) {
            worst_seconds = max(worst_seconds, get_bit_size(required[i] - arr[i]));
        }

        cout << worst_seconds << '\n';
    }
}