#include <algorithm>
#include <iostream>
#define INF 2147483647
using namespace std;

int dp[102];
int dist[102];
int duration[102];
int previous[102];
int visit_count[102];
int L, N;

void print_path(int cur) {
    if (previous[cur] != 0) {
        print_path(previous[cur]);
    }

    if (cur != N + 1) {
        cout << cur << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> L >> N;

    for (int i = 0; i <= N; i++) {
        cin >> dist[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> duration[i];
    }

    fill(dp + 1, dp + N + 2, INF);

    for (int i = 1; i <= N + 1; i++) {
        int current_dist = 0;

        for (int j = i - 1; j >= 0; j--) {
            current_dist += dist[j];
            if (current_dist > L) break;

            if (dp[j] + duration[i] <= dp[i]) {
                dp[i] = dp[j] + duration[i];
                previous[i] = j;
                visit_count[i] = visit_count[j] + 1;
            }
        }
    }

    cout << dp[N + 1] << '\n';
    cout << visit_count[N + 1] - 1 << '\n';
    print_path(N + 1);
}