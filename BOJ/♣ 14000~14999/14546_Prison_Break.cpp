#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Pos {
    int r, c;
};

char grid[12][12];
bool visited[12][12];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C, start_c, start_r, end_c, end_r;

bool can_escape() {
    fill(&visited[1][1], &visited[R][C + 1], false);
    queue<Pos> q;
    q.push({start_r, start_c});
    visited[start_r][start_c] = true;
    char type = grid[start_r][start_c];

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        if (cur.r == end_r && cur.c == end_c) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r >= 1 && r <= R && c >= 1 && c <= C && !visited[r][c] &&
                grid[r][c] == type) {
                visited[r][c] = true;
                q.push({r, c});
            }
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> C >> R >> start_c >> start_r >> end_c >> end_r;
        start_r = R - start_r + 1;
        end_r = R - end_r + 1;

        for (int r = 1; r <= R; r++) {
            cin >> (grid[r] + 1);
        }

        cout << (can_escape() ? "YES\n" : "NO\n");
    }
}
