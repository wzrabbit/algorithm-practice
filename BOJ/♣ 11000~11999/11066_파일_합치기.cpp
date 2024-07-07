#include <iostream>
#define INF 2'100'000'000
using namespace std;

int dp[501][501];
int prefix[501];

int get_sum(int start, int end) {
    return prefix[end] - prefix[start - 1];
}

int top_down(int start, int end) {
    int &cur = dp[start][end];

    if (cur != -1) {
        return dp[start][end];
    }

    cur = INF;

    for (int i = start; i <= end; i++) {
        cur = min(cur, top_down(start, i) + top_down(i + 1, end) + get_sum(start, i) + get_sum(i + 1, end));
    }

    return cur;
}

void solve() {
    int N;
    cin >> N;

    fill(&dp[1][1], &dp[N][N + 1], -1);

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        dp[i][i] = 0;
        prefix[i] = prefix[i - 1] + cur;
    }

    cout << top_down(1, N) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }
}
