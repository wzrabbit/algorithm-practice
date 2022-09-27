
#include <algorithm>
#include <iostream>
#define INF 10000000
using namespace std;

struct loc {
    int x, y;
};

loc point[501];
int dp[501][501];

int get_distance(int a, int b) {
    return abs(point[a].x - point[b].x) + abs(point[a].y - point[b].y);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> point[i].x >> point[i].y;
    }

    fill(&dp[0][2], &dp[K][N + 1], INF);

    for (int c = 2; c <= N; c++) {
        dp[0][c] = dp[0][c - 1] + get_distance(c - 1, c);
        // cout << "TEST: " << dp[0][c - 1] << ' ' << get_distance(c - 1, c) << '\n';
        // cout << "CHECK: " << dp[0][c];
    }

    for (int r = 1; r <= K; r++) {
        for (int c = 2; c <= N; c++) {
            dp[r][c] = min(dp[r - 1][c - 1], dp[r][c - 1] + get_distance(c - 1, c));
        }
    }

    for (int r = 0; r <= K; r++) {
        for (int c = 1; c <= N; c++)
            cout << dp[r][c] << ' ';
        cout << '\n';
    }

    cout << dp[K][N];
}