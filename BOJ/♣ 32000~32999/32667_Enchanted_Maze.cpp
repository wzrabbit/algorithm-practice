#include <algorithm>
#include <iostream>
#include <queue>
#define INF 1'000'000
using namespace std;

struct QData {
    int r1, c1, r2, c2, b, d;
};

char grid[12][12];
int dist[11][11][11][11][16];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C, start_r1, start_c1, start_r2, start_c2;

int get_escape_time() {
    fill(&dist[1][1][1][1][0], &dist[R][C][R][C][16], INF);
    dist[start_r1][start_c1][start_r2][start_c2][0] = 0;
    queue<QData> q;
    q.push({start_r1, start_c1, start_r2, start_c2, 0, 0});

    while (!q.empty()) {
        QData cur = q.front();
        q.pop();

        if (grid[cur.r1][cur.c1] == 'E' && grid[cur.r2][cur.c2] == 'E') {
            return cur.d;
        }

        for (int i = 0; i < 4; i++) {
            int r1 = cur.r1 + dr[i];
            int c1 = cur.c1 + dc[i];
            int r2 = cur.r2 + dr[i];
            int c2 = cur.c2 + dc[i];

            if (r1 < 1 || c1 < 1 || r2 < 1 || c2 < 1 || r1 > R || c1 > C ||
                r2 > R || c2 > C) {
                continue;
            }

            if (r1 == r2 && c1 == c2) {
                continue;
            }

            char next1 = grid[r1][c1];
            char next2 = grid[r2][c2];

            if (next1 == '*' || next2 == '*') {
                continue;
            }

            if (next1 == '#') {
                r1 = cur.r1;
                c1 = cur.c1;
            }

            if (next2 == '#') {
                r2 = cur.r2;
                c2 = cur.c2;
            }

            if (next1 >= 'A' && next1 <= 'D' &&
                (cur.b & (1 << (next1 - 'A'))) == 0) {
                r1 = cur.r1;
                c1 = cur.c1;
            }

            if (next1 >= 'a' && next1 <= 'd' &&
                (cur.b & (1 << (next1 - 'a'))) != 0) {
                r1 = cur.r1;
                c1 = cur.c1;
            }

            if (next2 >= 'A' && next2 <= 'D' &&
                (cur.b & (1 << (next2 - 'A'))) == 0) {
                r2 = cur.r2;
                c2 = cur.c2;
            }

            if (next2 >= 'a' && next2 <= 'd' &&
                (cur.b & (1 << (next2 - 'a'))) != 0) {
                r2 = cur.r2;
                c2 = cur.c2;
            }

            if (next1 >= '1' && next1 <= '4' &&
                (grid[cur.r2][cur.c2] == 'a' + (next1 - '1') ||
                 grid[cur.r2][cur.c2] == 'A' + (next1 - '1'))) {
                continue;
            }

            if (next2 >= '1' && next2 <= '4' &&
                (grid[cur.r1][cur.c1] == 'a' + (next2 - '1') ||
                 grid[cur.r1][cur.c1] == 'A' + (next2 - '1'))) {
                continue;
            }

            int new_bit = cur.b;

            if (next1 >= '1' && next1 <= '4' &&
                (cur.r1 != r1 || cur.c1 != c1)) {
                new_bit ^= (1 << (next1 - '1'));
            }

            if (next2 >= '1' && next2 <= '4' &&
                (cur.r2 != r2 || cur.c2 != c2)) {
                new_bit ^= (1 << (next2 - '1'));
            }

            if (dist[r1][c1][r2][c2][new_bit] == INF) {
                dist[r1][c1][r2][c2][new_bit] = cur.d + 1;
                q.push({r1, c1, r2, c2, new_bit, cur.d + 1});
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 'S') {
                if (start_r1 == 0) {
                    start_r1 = r;
                    start_c1 = c;
                } else {
                    start_r2 = r;
                    start_c2 = c;
                }
            }
        }
    }

    cout << get_escape_time();
}
