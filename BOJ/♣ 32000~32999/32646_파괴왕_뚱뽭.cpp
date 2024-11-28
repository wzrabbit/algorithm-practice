#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
typedef long long ll;
#define INF 2'000'000'000
using namespace std;

struct PQData {
    ll t, r, c, d;
};

bool operator<(const PQData &a, const PQData &b) { return a.d > b.d; }

struct Pos {
    ll r, c;
};

ll R, C, T, L, Q;
ll dist[101][101][101];
Pos teleport[101][101];
ll grid[101][101];
ll dr[4] = {-1, 1, 0, 0};
ll dc[4] = {0, 0, -1, 1};

void traverse() {
    priority_queue<PQData> pq;
    fill(&dist[0][1][1], &dist[L][R][C + 1], INF);
    pq.push({0, 1, 1, 0});
    dist[0][1][1] = 0;

    while (!pq.empty()) {
        PQData cur = pq.top();
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C) {
                continue;
            }

            ll next_dist = cur.d + grid[r][c];

            if (next_dist < dist[cur.t][r][c]) {
                dist[cur.t][r][c] = next_dist;
                pq.push({cur.t, r, c, next_dist});
            }
        }

        if (teleport[cur.r][cur.c].r != 0 && cur.t < L) {
            ll r = teleport[cur.r][cur.c].r;
            ll c = teleport[cur.r][cur.c].c;

            if (cur.d < dist[cur.t + 1][r][c]) {
                dist[cur.t + 1][r][c] = cur.d;
                pq.push({cur.t + 1, r, c, cur.d});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> T >> L >> Q;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    for (int i = 1; i <= T; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        teleport[r1][c1] = {r2, c2};
    }

    traverse();

    while (Q--) {
        ll p, r, c;
        cin >> p >> r >> c;

        ll required_p = INF;

        for (int i = 0; i <= L; i++) {
            required_p = min(required_p, dist[i][r][c]);
        }

        cout << (p >= required_p) << '\n';
    }
}
