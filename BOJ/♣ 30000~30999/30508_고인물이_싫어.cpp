#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Pos {
    int r, c;
};

int grid[1001][1001];
bool is_dry[1001][1001];
int prefix[1001][1001];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C, SR, SC;
queue<Pos> q;

void bfs() {
    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || is_dry[r][c] || grid[r][c] < grid[cur.r][cur.c]) {
                continue;
            }

            is_dry[r][c] = true;
            q.push({r, c});
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> SR >> SC;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    int Q;
    cin >> Q;

    for (int i = 1; i <= Q; i++) {
        int r, c;
        cin >> r >> c;

        q.push({r, c});
        is_dry[r][c] = true;
    }

    bfs();

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            prefix[r][c] = prefix[r - 1][c] + prefix[r][c - 1] - prefix[r - 1][c - 1] + is_dry[r][c];
        }
    }

    int answer = 0;

    for (int r = SR; r <= R; r++) {
        for (int c = SC; c <= C; c++) {
            if (prefix[r][c] - prefix[r - SR][c] - prefix[r][c - SC] + prefix[r - SR][c - SC] == SR * SC) {
                answer += 1;
            }
        }
    }

    cout << answer;
}
