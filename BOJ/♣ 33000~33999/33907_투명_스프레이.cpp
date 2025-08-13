#include <deque>
#include <iostream>
using namespace std;

struct State {
    int r, c, d;
};

int grid[701][701];
bool visited[701][701];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C, K;

bool is_possible(int limit) {
    deque<State> dq;
    dq.push_back({1, 1, 0});
    fill(&visited[1][1], &visited[R][C + 1], false);

    while (!dq.empty()) {
        State cur = dq.front();
        dq.pop_front();

        if (visited[cur.r][cur.c]) {
            continue;
        }

        visited[cur.r][cur.c] = true;

        if (cur.r == R && cur.c == C) {
            return cur.d <= K;
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C) {
                continue;
            }

            if (grid[r][c] > limit) {
                dq.push_back({r, c, cur.d + 1});
            } else {
                dq.push_front({r, c, cur.d});
            }
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> K;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    int start = 0;
    int end = 1'000'000'001;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (is_possible(mid)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << start;
}
