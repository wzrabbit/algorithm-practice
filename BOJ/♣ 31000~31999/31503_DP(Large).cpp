#include <algorithm>
#include <iostream>
#define INF 2'100'000'000
using namespace std;

int arr[300001];
int dp[300001];
int lis_left[300001];
int lis_right[300001];
int N, Q;

void generate_lis(int target[]) {
    fill(dp, dp + N + 1, INF);
    dp[0] = -INF;

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

        target[i] = end + 1;
        dp[end + 1] = min(arr[i], dp[end + 1]);
    }
}

int get_answer(int required) {
    return lis_left[required] + lis_right[required] - 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    generate_lis(lis_left);

    for (int i = 1; i <= N; i++) {
        arr[i] *= -1;
    }

    reverse(arr + 1, arr + N + 1);
    generate_lis(lis_right);
    reverse(lis_right + 1, lis_right + N + 1);

    while (Q--) {
        int cur;
        cin >> cur;

        cout << get_answer(cur) << '\n';
    }
}
