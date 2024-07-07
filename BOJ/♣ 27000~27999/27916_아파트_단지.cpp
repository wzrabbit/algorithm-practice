#include <iostream>
using namespace std;

int arr[300001];
int dp[300001];
int N, M, Q;

bool is_possible(int limit) {
    fill(dp + 1, dp + N + 1, 0);

    for (int i = M; i <= N; i++) {
        dp[i] = dp[i - 1];

        if (arr[i] - arr[dp[i - M] + 1] <= limit) {
            dp[i] = i;
        }
    }

    return dp[N] == N;
}

int get_minimum_apt_scale() {
    int start = 0;
    int end = 1'000'000'000;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (is_possible(mid)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return start;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int minimum_scale = get_minimum_apt_scale();

    for (int i = 1; i <= Q; i++) {
        int cur;
        cin >> cur;

        if (cur >= minimum_scale) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
}