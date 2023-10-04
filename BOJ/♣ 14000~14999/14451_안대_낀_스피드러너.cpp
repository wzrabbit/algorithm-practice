#include <algorithm>
#include <iostream>
#include <queue>
#define INF 3'456'789
using namespace std;

struct State {
    int r1, c1, d1, r2, c2, d2, f1, f2;
};

char grid[22][22];
int dist[21][21][4][21][21][4][2][2];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int di[2] = {-1, 1};
int N;

void bfs() {
    queue<State> q;
    q.push({N, 1, 0, N, 1, 1, 0, 0});
    fill(&dist[1][1][0][1][1][0][0][0], &dist[N][N][3][N][N][3][1][2], INF);
    dist[N][1][0][N][1][1][0][0] = 0;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();
        int cur_dist = dist[cur.r1][cur.c1][cur.d1][cur.r2][cur.c2][cur.d2][cur.f1][cur.f2];

        if (cur.f1 && cur.f2) {
            cout << cur_dist;
            break;
        }

        for (int i = 0; i < 2; i++) {
            int d1 = (cur.d1 + 4 + di[i]) % 4;
            int d2 = (cur.d2 + 4 + di[i]) % 4;

            if (dist[cur.r1][cur.c1][d1][cur.r2][cur.c2][d2][cur.f1][cur.f2] == INF) {
                dist[cur.r1][cur.c1][d1][cur.r2][cur.c2][d2][cur.f1][cur.f2] = cur_dist + 1;
                q.push({cur.r1, cur.c1, d1, cur.r2, cur.c2, d2, cur.f1, cur.f2});
            }
        }

        int r1 = cur.r1 + dr[cur.d1];
        int c1 = cur.c1 + dc[cur.d1];
        int r2 = cur.r2 + dr[cur.d2];
        int c2 = cur.c2 + dc[cur.d2];

        if (r1 > N || r1 < 1 || c1 > N || c1 < 1 || grid[r1][c1] == 'H') {
            r1 -= dr[cur.d1];
            c1 -= dc[cur.d1];
        }

        if (r2 > N || r2 < 1 || c2 > N || c2 < 1 || grid[r2][c2] == 'H') {
            r2 -= dr[cur.d2];
            c2 -= dc[cur.d2];
        }

        int f1 = cur.f1 | (r1 == 1 && c1 == N);
        int f2 = cur.f2 | (r2 == 1 && c2 == N);

        if (dist[r1][c1][cur.d1][r2][c2][cur.d2][f1][f2] != INF) {
            continue;
        }

        dist[r1][c1][cur.d1][r2][c2][cur.d2][f1][f2] = cur_dist + 1;
        q.push({r1, c1, cur.d1, r2, c2, cur.d2, f1, f2});
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int r = 1; r <= N; r++) {
        cin >> (grid[r] + 1);
    }

    bfs();
}
