#include <iostream>
#include <queue>
using namespace std;

struct Pos {
    int r, c;
};

char grid[1002][1002];
bool visited[1002][1002];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;

bool can_flow() {
    queue<Pos> q;

    for (int c = 1; c <= C; c++) {
        if (grid[1][c] == '0') {
            visited[1][c] = true;
            q.push({1, c});
        }
    }

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        if (cur.r == R) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || visited[r][c] || grid[r][c] == '1') {
                continue;
            }

            visited[r][c] = true;
            q.push({r, c});
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    cout << (can_flow() ? "YES" : "NO");
}
