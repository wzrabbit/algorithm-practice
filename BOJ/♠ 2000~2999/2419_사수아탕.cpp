#include <algorithm>
#include <iostream>
#define INF 300'000'001
using namespace std;

int N, M;

int positions[302];
int dp[302][302][2];  // dp[왼쪽까지 공략][오른쪽까지 공략][현재 방향] = 손실 사탕 개수

int top_down(int left, int right, int direction, int goal) {
    int &cur = dp[left][right][direction];

    if (cur != -1) {
        return cur;
    }

    if (goal == 0) {
        return cur = 0;
    }

    cur = INF;

    if (left > 1) {
        if (direction == 0) {
            int dist_gap = abs(positions[left] - positions[left - 1]);
            cur = min(cur, top_down(left - 1, right, 0, goal - 1) + dist_gap * goal);
        } else {
            int dist_gap = abs(positions[right] - positions[left - 1]);
            cur = min(cur, top_down(left - 1, right, 0, goal - 1) + dist_gap * goal);
        }
    }

    if (right < N + 1) {
        if (direction == 0) {
            int dist_gap = abs(positions[left] - positions[right + 1]);
            cur = min(cur, top_down(left, right + 1, 1, goal - 1) + dist_gap * goal);
        } else {
            int dist_gap = abs(positions[right] - positions[right + 1]);
            cur = min(cur, top_down(left, right + 1, 1, goal - 1) + dist_gap * goal);
        }
    }

    return cur;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> positions[i];
    }

    positions[N + 1] = 0;

    sort(positions + 1, positions + N + 2);

    int zero_position;

    for (int i = 1; i <= N + 1; i++) {
        if (positions[i] == 0) {
            zero_position = i;
            break;
        }
    }

    int best_candy_count = 0;

    for (int i = 1; i <= N; i++) {
        fill(&dp[0][0][0], &dp[N + 1][N + 1][2], -1);
        int cur_candy_count = M * i - top_down(zero_position, zero_position, 0, i);
        best_candy_count = max(best_candy_count, cur_candy_count);
    }

    cout << best_candy_count;
}
