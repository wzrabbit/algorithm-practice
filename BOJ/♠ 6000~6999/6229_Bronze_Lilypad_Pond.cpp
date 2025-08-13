#include <iostream>
#include <queue>
using namespace std;

struct Pos {
    int r, c;
};

int R, C, A, B;
vector<int> dr, dc;
int grid[31][31];
int dist[31][31];

int get_dist(Pos start) {
    queue<Pos> q;
    q.push(start);
    fill(&dist[1][1], &dist[R][C + 1], -1);
    dist[start.r][start.c] = 0;

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        if (grid[cur.r][cur.c] == 4) {
            return dist[cur.r][cur.c];
        }

        for (int i = 0; i < 8; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || dist[r][c] != -1 ||
                grid[r][c] == 0 || grid[r][c] == 2) {
                continue;
            }

            dist[r][c] = dist[cur.r][cur.c] + 1;
            q.push({r, c});
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> A >> B;

    dr = {-A, -A, -B, -B, A, A, B, B};
    dc = {-B, B, -A, A, -B, B, -A, A};

    Pos start;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];

            if (grid[r][c] == 3) {
                start.r = r;
                start.c = c;
            }
        }
    }

    cout << get_dist(start);
}
