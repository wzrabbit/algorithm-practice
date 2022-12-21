#include <algorithm>
#include <iostream>
#include <queue>
#define INF 3000000
using namespace std;

struct Loc {
    int r, c, d;
};

bool operator<(Loc x, Loc y) {
    return x.d > y.d;
}

int city[1000][1000];
int dist[1000][1000];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> city[r][c];
        }
    }

    if (city[0][0] == -1) {
        cout << -1;
        return 0;
    }

    fill(&dist[0][0], &dist[999][1000], INF);
    dist[0][0] = city[0][0];

    priority_queue<Loc> pq;
    pq.push({0, 0, city[0][0]});

    while (!pq.empty()) {
        Loc cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.r][cur.c]) continue;

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r >= 0 && r < R && c >= 0 && c < C && city[r][c] != -1 && cur.d + city[r][c] < dist[r][c]) {
                dist[r][c] = cur.d + city[r][c];
                pq.push({r, c, cur.d + city[r][c]});
            }
        }
    }

    if (dist[R - 1][C - 1] < INF) {
        cout << dist[R - 1][C - 1];
    } else {
        cout << -1;
    }
}