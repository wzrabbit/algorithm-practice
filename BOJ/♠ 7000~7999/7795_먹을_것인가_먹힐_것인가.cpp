#include <algorithm>
#include <iostream>
using namespace std;

int arr[20001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        int answer = 0;

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        sort(arr + 1, arr + N + 1);

        for (int i = 1; i <= M; i++) {
            int cur;
            cin >> cur;

            int start = 1;
            int end = N;
            int mid;

            while (start <= end) {
                mid = (start + end) / 2;

                if (arr[mid] > cur) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }

            answer += N - start + 1;
        }

        cout << answer << '\n';
    }
}
