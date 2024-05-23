#include <algorithm>
#include <iostream>
#include <queue>
#define INF 9'876'543
using namespace std;

struct Loc {
    int r, c;
};

int grid[1001][1001];
int dist[1001][1001];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;
int start_r, start_c;

void init() {
    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    fill(&dist[1][1], &dist[R][C + 1], INF);
}

void assign_start_location() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 2) {
                start_r = r;
                start_c = c;
                return;
            }
        }
    }
}

void perform_bfs() {
    queue<Loc> q;
    q.push({start_r, start_c});
    dist[start_r][start_c] = 0;

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || dist[r][c] != INF || grid[r][c] != 1) {
                continue;
            }

            dist[r][c] = dist[cur.r][cur.c] + 1;
            q.push({r, c});
        }
    }
}

void print_answer() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 0) {
                cout << 0 << ' ';
            } else if (dist[r][c] == INF) {
                cout << -1 << ' ';
            } else {
                cout << dist[r][c] << ' ';
            }
        }

        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    init();
    assign_start_location();
    perform_bfs();

    print_answer();
}
