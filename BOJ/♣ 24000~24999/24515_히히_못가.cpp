#include <algorithm>
#include <iostream>
#include <queue>
#define INF 10000000
using namespace std;

struct loc {
    int r, c;
};

struct p_loc {
    int r, c, d;
};

bool operator<(p_loc a, p_loc b) {
    return a.d > b.d;
}

char board[1001][1001];
int area[1000][1000];
int scale[1000001];
int dist[1000][1000];
int id = 1;
int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

void bfs(int start_r, int start_c, int N, int id, int alph) {
    if (area[start_r][start_c] != 0 || board[start_r][start_c] == '.')
        return;

    queue<loc> q;
    q.push({start_r, start_c});
    area[start_r][start_c] = id;

    while (q.size()) {
        loc cur = q.front();
        q.pop();
        scale[id]++;

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r >= 0 && r < N && c >= 0 && c < N && area[r][c] == 0 && board[r][c] == alph) {
                area[r][c] = id;
                q.push({r, c});
            }
        }
    }
}

void dijkstra(int N) {
    priority_queue<p_loc> pq;
    fill(&dist[0][0], &dist[N - 1][N], INF);

    for (int r = 1; r < N; r++) {
        dist[r][0] = scale[area[r][0]];
        pq.push({r, 0, scale[area[r][0]]});
    }

    for (int c = 1; c < N - 1; c++) {
        dist[N - 1][c] = scale[area[N - 1][c]];
        pq.push({N - 1, c, scale[area[N - 1][c]]});
    }

    while (pq.size()) {
        p_loc cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.r][cur.c])
            continue;

        for (int i = 0; i < 8; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r >= 0 && r < N && c >= 0 && c < N && board[r][c] != '.') {
                if (area[cur.r][cur.c] == area[r][c] && cur.d < dist[r][c]) {
                    dist[r][c] = cur.d;
                    pq.push({r, c, cur.d});
                } else if (cur.d + scale[area[r][c]] < dist[r][c]) {
                    dist[r][c] = cur.d + scale[area[r][c]];
                    pq.push({r, c, cur.d + scale[area[r][c]]});
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int r = 0; r < N; r++)
        cin >> board[r];

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++)
            bfs(r, c, N, id++, board[r][c]);
    }

    dijkstra(N);

    int best = INF;
    for (int c = 1; c < N; c++) {
        if (dist[0][c] < best)
            best = dist[0][c];
    }

    for (int r = 1; r < N - 1; r++) {
        if (dist[r][N - 1] < best)
            best = dist[r][N - 1];
    }

    cout << best;
}