#include <algorithm>
#include <iostream>
#define INF 1'234'567
using namespace std;

int arr[3001];
int dp[3001];
int N, Q;

int find_longest_index(int cur_index) {
    int start = 0;
    int end = N - 1;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (dp[mid] < arr[cur_index]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return end;
}

int get_answer(int required) {
    fill(dp, dp + N + 1, INF);
    dp[0] = -INF;
    int longest = 0;

    for (int i = 1; i <= required; i++) {
        int longest_index = find_longest_index(i);
        dp[longest_index + 1] = min(arr[i], dp[longest_index + 1]);

        if (i == required) {
            longest = longest_index + 1;
        }
    }

    for (int i = 1; i <= longest; i++) {
        dp[i] = arr[required];
    }

    for (int i = longest + 1; i <= N; i++) {
        dp[i] = INF;
    }

    for (int i = required + 1; i <= N; i++) {
        int longest_index = find_longest_index(i);

        if (longest_index == 0) {
            continue;
        }

        dp[longest_index + 1] = min(arr[i], dp[longest_index + 1]);
        longest = max(longest, longest_index + 1);
    }

    return longest;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    while (Q--) {
        int cur;
        cin >> cur;

        cout << get_answer(cur) << '\n';
    }
}
