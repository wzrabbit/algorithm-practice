#include <algorithm>
#include <iostream>
#define INF 100'000
using namespace std;

int grid[2][10001];
int dp[10001][3];
int N, power;

int get_1_answer() {
    if (grid[0][1] + grid[1][1] <= power) {
        return 1;
    }

    return 2;
}

int get_answer(int mode) {
    bool top_locked = (mode & 1) > 0;
    bool bottom_locked = (mode & 2) > 0;

    if (top_locked && grid[0][1] + grid[0][N] > power) {
        return INF;
    }

    if (bottom_locked && grid[1][1] + grid[1][N] > power) {
        return INF;
    }

    fill(&dp[0][0], &dp[N][3], INF);

    switch (mode) {
        case 0:
            dp[0][0] = 0;
            break;
        case 1:
            dp[1][1] = 1;
            break;
        case 2:
            dp[1][2] = 1;
            break;
        case 3:
            dp[1][0] = 2;
            break;
    }

    for (int i = 0; i <= N; i++) {
        if (dp[i][1] != INF) {
            dp[i][0] = min(dp[i][0], dp[i][1] + 1);

            if (i < N && grid[1][i] + grid[1][i + 1] <= power) {
                dp[i + 1][2] = min(dp[i + 1][2], dp[i][1] + 1);
            }
        }

        if (dp[i][2] != INF) {
            dp[i][0] = min(dp[i][0], dp[i][2] + 1);

            if (i < N && grid[0][i] + grid[0][i + 1] <= power) {
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][2] + 1);
            }
        }

        if (dp[i][0] != INF && i < N) {
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + 1);
            dp[i + 1][2] = min(dp[i + 1][2], dp[i][0] + 1);

            if (grid[0][i + 1] + grid[1][i + 1] <= power) {
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + 1);
            }

            if (i < N - 1 && grid[0][i + 1] + grid[0][i + 2] <= power) {
                dp[i + 2][1] = min(dp[i + 2][1], dp[i][0] + 2);
            }

            if (i < N - 1 && grid[1][i + 1] + grid[1][i + 2] <= power) {
                dp[i + 2][2] = min(dp[i + 2][2], dp[i][0] + 2);
            }

            if (i < N - 1 && grid[0][i + 1] + grid[0][i + 2] <= power &&
                grid[1][i + 1] + grid[1][i + 2] <= power) {
                dp[i + 2][0] = min(dp[i + 2][0], dp[i][0] + 2);
            }
        }
    }

    switch (mode) {
        case 0:
            return dp[N][0];
        case 1:
            return dp[N][2];
        case 2:
            return dp[N][1];
        default:
            return dp[N - 1][0];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> N >> power;

        for (int i = 1; i <= 2 * N; i++) {
            cin >> grid[(i - 1) / N][(i - 1) % N + 1];
        }

        if (N == 1) {
            cout << get_1_answer() << '\n';
            continue;
        }

        int answer = INF;

        for (int i = 0; i < 4; i++) {
            answer = min(answer, get_answer(i));
        }

        cout << answer << '\n';
    }
}
