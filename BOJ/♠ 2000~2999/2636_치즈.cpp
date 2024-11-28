#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Pos {
    int r, c;
};

int R, C;
bool grid[102][102];
bool visited[102][102];
bool should_melt[102][102];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void melt_cheese() {
    queue<Pos> q;
    q.push({0, 0});
    fill(&should_melt[1][1], &should_melt[R][C + 1], false);
    fill(&visited[0][0], &visited[R + 1][C + 2], false);
    visited[0][0] = true;

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 0 || r > R + 1 || c < 0 || c > C + 1 || visited[r][c]) {
                continue;
            }

            if (grid[r][c] == 0) {
                visited[r][c] = true;
                q.push({r, c});
            } else {
                should_melt[r][c] = true;
            }
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (should_melt[r][c]) {
                grid[r][c] = 0;
            }
        }
    }
}

int get_left_cheese_count() {
    int cheese_count = 0;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 1) {
                cheese_count += 1;
            }
        }
    }

    return cheese_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    int prev_left_cheese_count = 0;
    int elapsed_time = 0;

    while (true) {
        int left_cheese_count = get_left_cheese_count();

        if (left_cheese_count == 0) {
            cout << elapsed_time << '\n'
                 << prev_left_cheese_count;

            return 0;
        }

        melt_cheese();

        prev_left_cheese_count = left_cheese_count;
        elapsed_time += 1;
    }
}
