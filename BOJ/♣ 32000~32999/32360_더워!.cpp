#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Loc {
    int l, r, c, d;
};

bool visited[101][101][101];
char grid[102][102];
int dr[5] = {0, -1, 1, 0, 0};
int dc[5] = {0, 0, 0, -1, 1};
int R, C, down, up;
int start_r, start_c, end_r, end_c;

int get_minimum_time(int start_r, int start_c) {
    queue<Loc> q;
    visited[0][start_r][start_c] = true;
    q.push({0, start_r, start_c, 0});

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();

        if (cur.r == end_r && cur.c == end_c) {
            return cur.d;
        }

        for (int i = 0; i < 5; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];
            int l = cur.l;
            int d = cur.d + 1;

            if (r < 1 || r > R || c < 1 || c > C || grid[r][c] == '#') {
                continue;
            }

            if (grid[r][c] == '.' || grid[r][c] == 'E') {
                l = min(l + up, 100);
            } else {
                l = max(l - down, 0);
            }

            if (l == 100 || visited[l][r][c]) {
                continue;
            }

            visited[l][r][c] = true;
            q.push({l, r, c, d});
        }
    }

    return -1;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> down >> up;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 'S') {
                start_r = r;
                start_c = c;
            }

            if (grid[r][c] == 'E') {
                end_r = r;
                end_c = c;
            }
        }
    }

    cout << get_minimum_time(start_r, start_c);
}
