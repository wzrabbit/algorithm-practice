#include <algorithm>
#include <iostream>
using namespace std;

int arr[10001];

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

        int answer = 0;

        for (int i = 3; i <= N; i += 2) {
            answer = max(answer, arr[i] - arr[i - 2]);
        }

        for (int i = 4; i <= N; i += 2) {
            answer = max(answer, arr[i] - arr[i - 2]);
        }

        answer = max(answer, arr[2] - arr[1]);
        answer = max(answer, arr[N] - arr[N - 1]);

        cout << answer << '\n';
    }
}
