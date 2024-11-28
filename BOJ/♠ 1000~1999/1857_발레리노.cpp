#include <iostream>
#include <queue>
#define INF 1'000'000'000
typedef long long ll;
using namespace std;

struct Pos {
    int r, c;
};

int grid[31][31];
vector<Pos> graph[31][31];
bool visited[31][31];
int dist[31][31];
ll cnt[31][31];
int R, C;
int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void make_graph(Pos start) {
    if (grid[start.r][start.c] == 2) {
        return;
    }

    fill(&visited[1][1], &visited[R][C + 1], false);
    queue<Pos> q;
    q.push(start);
    visited[start.r][start.c] = true;

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || visited[r][c] ||
                grid[r][c] == 2) {
                continue;
            }

            visited[r][c] = true;

            if (grid[r][c] == 1) {
                q.push({r, c});
                continue;
            }

            graph[start.r][start.c].push_back({r, c});
        }
    }
}

void traverse(Pos start, Pos end) {
    fill(&dist[1][1], &dist[R][C + 1], INF);
    dist[start.r][start.c] = 0;
    cnt[start.r][start.c] = 1;
    queue<Pos> q;
    q.push(start);

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        if (cur.r == end.r && cur.c == end.c) {
            return;
        }

        for (Pos adj : graph[cur.r][cur.c]) {
            int next_dist = dist[cur.r][cur.c] + 1;

            if (dist[adj.r][adj.c] == INF) {
                q.push({adj.r, adj.c});
            }

            if (next_dist <= dist[adj.r][adj.c]) {
                dist[adj.r][adj.c] = next_dist;
                cnt[adj.r][adj.c] += cnt[cur.r][cur.c];
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    Pos start, end;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];

            if (grid[r][c] == 3) {
                start = {r, c};
                continue;
            }

            if (grid[r][c] == 4) {
                end = {r, c};
            }
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            make_graph({r, c});
        }
    }

    traverse(start, end);

    if (dist[end.r][end.c] == INF) {
        cout << -1;
        return 0;
    }

    cout << dist[end.r][end.c] - 1 << '\n' << cnt[end.r][end.c];
}
