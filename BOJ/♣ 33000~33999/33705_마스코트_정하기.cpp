#include <iostream>
using namespace std;

int arr[200001];
int answer[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int one_count = 0;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];

        if (arr[i] == 1) {
            one_count += 1;
        }
    }

    if (one_count >= (N - N / 2)) {
        cout << 0;
        return 0;
    }

    one_count = 0;

    for (int i = 1; i <= N - 1; i++) {
        if (arr[i] == 1) {
            one_count += 1;
        }

        if (one_count >= (i - i / 2)) {
            cout << 1;
            return 0;
        }
    }

    one_count = 0;

    for (int i = N; i >= 1; i--) {
        if (arr[i] == 1) {
            one_count += 1;
        }

        if (one_count >= ((N - i + 1) - (N - i + 1) / 2)) {
            cout << 1;
            return 0;
        }
    }

    cout << 2;
}
