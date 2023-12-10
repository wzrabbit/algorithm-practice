#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Pos {
    int r, c, d;
};

char grid[202][202];
bool visited[4][202][202];
int wall[202][202];
int dr[5] = {0, 1, 0, -1, 0};
int dc[5] = {1, 0, -1, 0, 0};
int R, C, start_R, start_C, end_R, end_C;

void make_ghost_sight(int ghost_R, int ghost_C, int direction) {
    wall[ghost_R][ghost_C] = 15;

    for (int i = 0; i < 4; i++) {
        int r = ghost_R + dr[(direction + i) % 4];
        int c = ghost_C + dc[(direction + i) % 4];

        while (r >= 1 && r <= R && c >= 1 && c <= C && grid[r][c] == '.') {
            wall[r][c] |= (1 << i);

            r += dr[(direction + i) % 4];
            c += dc[(direction + i) % 4];
        }
    }
}

int get_escape_time() {
    queue<Pos> q;
    q.push({start_R, start_C, 0});
    visited[0][start_R][start_C] = true;

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        if (cur.r == end_R && cur.c == end_C) {
            return cur.d;
        }

        int lv = (cur.d + 1) % 4;

        for (int i = 0; i < 5; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (
                r < 1 ||
                r > R ||
                c < 1 ||
                c > C ||
                visited[lv][r][c] ||
                ((wall[r][c] & (1 << lv)) != 0)) {
                continue;
            }

            q.push({r, c, cur.d + 1});
            visited[lv][r][c] = true;
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> start_R >> start_C >> end_R >> end_C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == '#') {
                wall[r][c] = 15;
                continue;
            }

            if (grid[r][c] >= '0' && grid[r][c] <= '3') {
                make_ghost_sight(r, c, grid[r][c] - '0');
            }
        }
    }

    int escape_time = get_escape_time();

    if (escape_time == -1) {
        cout << "GG";
    } else {
        cout << escape_time;
    }
}