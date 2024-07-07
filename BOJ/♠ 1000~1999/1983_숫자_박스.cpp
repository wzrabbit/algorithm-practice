#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <vector>
#define INF 100000
#define NOT_VISITED -200000
using namespace std;

int dp[401][401][401];
int up_values[401];
int down_values[401];

int perform_top_down(int n, int u, int d) {
    if (n == 0) {
        return u == 0 && d == 0 ? 0 : -INF;
    }

    if (n < u || n < d || u < 0 || d < 0) {
        return -INF;
    }

    int &cur = dp[n][u][d];

    if (cur != NOT_VISITED) {
        return cur;
    }

    return cur = max({perform_top_down(n - 1, u - 1, d - 1) + up_values[u] * down_values[d],
                      perform_top_down(n - 1, u - 1, d),
                      perform_top_down(n - 1, u, d - 1),
                      perform_top_down(n - 1, u, d)});
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int U = 0, D = 0;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        if (cur != 0) {
            U += 1;
            up_values[U] = cur;
        }
    }

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        if (cur != 0) {
            D += 1;
            down_values[D] = cur;
        }
    }

    fill(&dp[0][0][0], &dp[N][U][D + 1], NOT_VISITED);

    cout << perform_top_down(N, U, D);
}
