#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Pos {
    int l, r, c, d;
};

char grid[52][52];
bool visited[1 << 5][51][51];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int things_count = 0;

int get_dist(int start_R, int start_C, int R, int C) {
    queue<Pos> q;
    q.push({0, start_R, start_C, 0});
    visited[0][start_R][start_C] = true;

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        if (cur.l == ((1 << things_count) - 1) && grid[cur.r][cur.c] == 'E') {
            return cur.d;
        }

        for (int i = 0; i < 4; i++) {
            int l = cur.l;
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];
            int d = cur.d + 1;

            if (r < 1 || r > R || c < 1 || c > C || grid[r][c] == '#') {
                continue;
            }

            if (grid[r][c] >= '0' && grid[r][c] <= '4') {
                l |= (1 << (grid[r][c] - '0'));
            }

            if (visited[l][r][c]) {
                continue;
            }

            q.push({l, r, c, d});
            visited[l][r][c] = true;
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> C >> R;

    int start_R = 0;
    int start_C = 0;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);

        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 'X') {
                grid[r][c] = '0' + things_count;
                things_count += 1;
                continue;
            }

            if (grid[r][c] == 'S') {
                start_R = r;
                start_C = c;
            }
        }
    }

    cout << get_dist(start_R, start_C, R, C);
}
