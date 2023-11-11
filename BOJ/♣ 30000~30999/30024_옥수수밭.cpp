#include <iostream>
#include <queue>
using namespace std;

struct Corn {
    int r, c, s;
};

bool operator<(const Corn& a, const Corn& b) {
    return a.s < b.s;
};

int grid[1001][1001];
bool visited[1001][1001];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C, K;

void gather_corns() {
    priority_queue<Corn> pq;

    for (int r = 1; r <= R; r++) {
        pq.push({r, 1, grid[r][1]});
        visited[r][1] = true;
    }

    if (C > 1) {
        for (int r = 1; r <= R; r++) {
            pq.push({r, C, grid[r][C]});
            visited[r][C] = true;
        }
    }

    for (int c = 2; c <= C - 1; c++) {
        pq.push({1, c, grid[1][c]});
        visited[1][c] = true;
    }

    if (R > 1) {
        for (int c = 2; c <= C - 1; c++) {
            pq.push({R, c, grid[R][c]});
            visited[R][c] = true;
        }
    }

    for (int i = 1; i <= K; i++) {
        Corn cur = pq.top();
        pq.pop();

        cout << cur.r << ' ' << cur.c << '\n';

        for (int j = 0; j < 4; j++) {
            int r = cur.r + dr[j];
            int c = cur.c + dc[j];

            if (r < 1 || r > R || c < 1 || c > C || visited[r][c]) {
                continue;
            }

            visited[r][c] = true;
            pq.push({r, c, grid[r][c]});
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    cin >> K;

    gather_corns();
}
