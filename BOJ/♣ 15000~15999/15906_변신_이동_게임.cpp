#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 200'000'000
using namespace std;

struct Loc {
    int r, c;
};

struct Node {
    int l, r, c, d;
};

bool operator<(const Node a, const Node b) {
    return a.d > b.d;
}

char grid[502][502];
int dist[2][502][502];
vector<Loc> special_graph[502][502];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int N, T, start_r, start_c;

void make_special_graph() {
    for (int r = 1; r <= N; r++) {
        int prev = -1;

        for (int c = 1; c <= N; c++) {
            if (prev != -1) {
                special_graph[r][c].push_back({r, prev});
            }

            if (grid[r][c] == '#') {
                prev = c;
            }
        }
    }

    for (int r = 1; r <= N; r++) {
        int prev = -1;

        for (int c = N; c >= 1; c--) {
            if (prev != -1) {
                special_graph[r][c].push_back({r, prev});
            }

            if (grid[r][c] == '#') {
                prev = c;
            }
        }
    }

    for (int c = 1; c <= N; c++) {
        int prev = -1;

        for (int r = 1; r <= N; r++) {
            if (prev != -1) {
                special_graph[r][c].push_back({prev, c});
            }

            if (grid[r][c] == '#') {
                prev = r;
            }
        }
    }

    for (int c = 1; c <= N; c++) {
        int prev = -1;

        for (int r = N; r >= 1; r--) {
            if (prev != -1) {
                special_graph[r][c].push_back({prev, c});
            }

            if (grid[r][c] == '#') {
                prev = r;
            }
        }
    }
}

void dijkstra() {
    fill(&dist[0][1][1], &dist[1][N][N + 1], INF);

    priority_queue<Node> pq;
    pq.push({0, 1, 1, 0});
    dist[0][1][1] = 0;

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.l][cur.r][cur.c]) {
            continue;
        }

        dist[cur.l][cur.r][cur.c] = cur.d;

        if (cur.l == 0) {
            for (size_t i = 0; i < 4; i++) {
                int r = cur.r + dr[i];
                int c = cur.c + dc[i];

                if (r < 1 || r > N || c < 1 || c > N || cur.d + 1 >= dist[0][r][c]) {
                    continue;
                }

                pq.push({0, r, c, cur.d + 1});
                dist[0][r][c] = cur.d + 1;
            }

            if (cur.d + T < dist[1][cur.r][cur.c]) {
                pq.push({1, cur.r, cur.c, cur.d + T});
                dist[1][cur.r][cur.c] = cur.d + T;
            }

            continue;
        }

        for (size_t i = 0; i < special_graph[cur.r][cur.c].size(); i++) {
            int next_r = special_graph[cur.r][cur.c][i].r;
            int next_c = special_graph[cur.r][cur.c][i].c;

            if (cur.d + 1 >= dist[1][next_r][next_c]) {
                continue;
            }

            pq.push({1, next_r, next_c, cur.d + 1});
            dist[1][next_r][next_c] = cur.d + 1;
        }

        if (cur.d < dist[0][cur.r][cur.c]) {
            pq.push({0, cur.r, cur.c, cur.d});
            dist[0][cur.r][cur.c] = cur.d;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> T >> start_r >> start_c;

    for (int r = 1; r <= N; r++) {
        cin >> (grid[r] + 1);
    }

    make_special_graph();
    dijkstra();

    cout << min(dist[0][start_r][start_c], dist[1][start_r][start_c]);
}