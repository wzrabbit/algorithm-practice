#include <algorithm>
#include <iostream>
#define INF 1'000'000'001
using namespace std;

int N, L;

int positions[1002];
int dp[1002][1002][2];

int top_down(int left, int right, int direction) {
    int &cur = dp[left][right][direction];

    if (cur != -1) {
        return cur;
    }

    if (left == 1 && right == N + 1) {
        return cur = 0;
    }

    cur = INF;
    int left_kimchi_count = N - (right - left);

    if (left > 1) {
        if (direction == 0) {
            int dist_gap = abs(positions[left] - positions[left - 1]);
            cur = min(cur, top_down(left - 1, right, 0) + dist_gap * left_kimchi_count);
        } else {
            int dist_gap = abs(positions[right] - positions[left - 1]);
            cur = min(cur, top_down(left - 1, right, 0) + dist_gap * left_kimchi_count);
        }
    }

    if (right < N + 1) {
        if (direction == 0) {
            int dist_gap = abs(positions[left] - positions[right + 1]);
            cur = min(cur, top_down(left, right + 1, 1) + dist_gap * left_kimchi_count);
        } else {
            int dist_gap = abs(positions[right] - positions[right + 1]);
            cur = min(cur, top_down(left, right + 1, 1) + dist_gap * left_kimchi_count);
        }
    }

    return cur;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> L;

    for (int i = 1; i <= N; i++) {
        cin >> positions[i];
    }

    positions[N + 1] = L;

    sort(positions + 1, positions + N + 2);

    int factory_position;

    for (int i = 1; i <= N + 1; i++) {
        if (positions[i] == L) {
            factory_position = i;
            break;
        }
    }

    fill(&dp[0][0][0], &dp[N + 1][N + 1][2], -1);

    cout << top_down(factory_position, factory_position, 0);
}
