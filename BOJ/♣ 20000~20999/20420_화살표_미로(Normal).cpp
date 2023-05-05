#include <algorithm>
#include <iostream>
#include <queue>
#define INF 30000
using namespace std;

struct Loc {
    int r, c, l_used, r_used;
};

bool operator<(Loc a, Loc b) {
    return a.l_used > b.l_used;
}

short dist[151][51][51];
char raw[152][152];
short maze[151][151];
short dr[4] = {-1, 0, 1, 0};
short dc[4] = {0, 1, 0, -1};
short R, C, K;

void create_maze() {
    cin >> R >> C >> K;

    for (int r = 1; r <= R; r++) {
        cin >> (raw[r] + 1);
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            switch (raw[r][c]) {
                case 'R':
                    maze[r][c] = 3;
                    break;
                case 'D':
                    maze[r][c] = 2;
                    break;
                case 'L':
                    maze[r][c] = 1;
                    break;
            }
        }
    }
}

void dijkstra() {
    fill(&dist[0][1][1], &dist[K][R][C + 1], INF);
    dist[0][1][1] = 0;
    priority_queue<Loc> pq;
    pq.push({1, 1, 0, 0});

    while (!pq.empty()) {
        Loc cur = pq.top();
        pq.pop();

        if (cur.l_used > dist[cur.r_used][cur.r][cur.c]) {
            continue;
        }

        if (cur.r == R && cur.c == C) {
            cout << "Yes";
            return;
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C) {
                continue;
            }

            int r_cost = (maze[cur.r][cur.c] + i) % 4;
            int l_cost = 4 - r_cost;

            if (cur.r_used + r_cost <= K && cur.l_used < dist[cur.r_used + r_cost][r][c]) {
                dist[cur.r_used + r_cost][r][c] = cur.l_used;
                pq.push({r, c, cur.l_used, cur.r_used + r_cost});
            }

            if (cur.l_used + l_cost <= K && cur.l_used + l_cost < dist[cur.r_used][r][c]) {
                dist[cur.r_used][r][c] = cur.l_used + l_cost;
                pq.push({r, c, cur.l_used + l_cost, cur.r_used});
            }
        }
    }

    cout << "No";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    create_maze();
    dijkstra();
}