#include <algorithm>
#include <iostream>
#define INF 40001
using namespace std;

int arr[40001];
int dp[40001];

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

        fill(dp + 1, dp + N + 1, INF);
        int longest = 1;

        for (int i = 1; i <= N; i++) {
            int start = 0;
            int end = N - 1;
            int mid;

            while (start <= end) {
                mid = (start + end) / 2;

                if (dp[mid] < arr[i]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }

            longest = max(longest, end + 1);
            dp[end + 1] = min(dp[end + 1], arr[i]);
        }

        cout << longest << '\n';
    }
}