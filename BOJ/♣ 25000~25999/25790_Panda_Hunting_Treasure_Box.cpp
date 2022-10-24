#include <algorithm>
#include <iostream>
#include <queue>
#define INF 2000000
using namespace std;

struct loc {
    int r, c, d;
};

bool operator<(loc a, loc b) {
    return a.d > b.d;
};

int grid[501][501];
int dist[501][501];
int dr[9] = {0, -1, -1, -1, 0, 1, 1, 1, 0};
int dc[9] = {0, -1, 0, 1, 1, 1, 0, -1, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C, start_R, start_C, energy;
    cin >> R >> C >> start_R >> start_C >> energy;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    fill(&dist[1][1], &dist[R][C + 1], INF);
    dist[start_R][start_C] = 0;
    priority_queue<loc> pq;
    pq.push({start_R, start_C, 0});

    while (pq.size()) {
        loc cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.r][cur.c] || grid[cur.r][cur.c] > 0) {
            continue;
        }

        for (int i = 1; i <= 8; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (1 <= r && r <= R && 1 <= c && c <= C && cur.d + i < dist[r][c]) {
                dist[r][c] = cur.d + i;
                pq.push({r, c, cur.d + i});
            }
        }
    }

    int best = 0;
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (dist[r][c] <= energy) {
                best = max(best, grid[r][c]);
            }
        }
    }

    cout << best;
}