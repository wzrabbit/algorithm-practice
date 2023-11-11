#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Pos {
    int l, r, c, d;
};

char grid[1002][1002];
bool visited[2][1001][1001];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;

int bfs(int start_r, int start_c) {
    queue<Pos> q;
    q.push({0, start_r, start_c, 0});
    visited[0][start_r][start_c] = true;

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        if (cur.l == 1 && grid[cur.r][cur.c] == 'H') {
            return cur.d;
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || !visited[r][c] || grid[r][c] == 'D') {
                continue;
            }

            int next_level = cur.l | (grid[r][c] == 'F');

            if (!visited[next_level][r][c]) {
                q.push({next_level, r, c, cur.d + 1});
                visited[next_level][r][c] = true;
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    int start_r = 0;
    int start_c = 0;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);

        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 'S') {
                start_r = r;
                start_c = c;
            }
        }
    }

    cout << bfs(start_r, start_c);
}
