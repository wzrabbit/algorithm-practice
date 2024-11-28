#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Pos {
    int r, c, d;
};

bool operator<(const Pos &a, const Pos &b) { return a.d > b.d; }

char grid[502][502];
int dist[502][502];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;

void make_dist() {
    fill(&dist[1][1], &dist[R][C + 1], -1);
    priority_queue<Pos> pq;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 'G') {
                dist[r][c] = 0;
                pq.push({r, c, 0});
            }
        }
    }

    while (!pq.empty()) {
        Pos cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.r][cur.c]) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || grid[r][c] == '#') {
                continue;
            }

            vector<int> adj_state;

            for (int j = 0; j < 4; j++) {
                int nr = r + dr[j];
                int nc = c + dc[j];

                if (nr < 1 || nr > R || nc < 1 || nc > C ||
                    dist[nr][nc] == -1 || grid[nr][nc] == '#') {
                    continue;
                }

                adj_state.push_back(dist[nr][nc]);
            }

            sort(adj_state.begin(), adj_state.end());

            if (adj_state.size() >= 2) {
                int next_dist = adj_state[1] + 1;

                if (dist[r][c] == -1 || next_dist < dist[r][c]) {
                    dist[r][c] = next_dist;
                    pq.push({r, c, next_dist});
                }
            }
        }
    }
}

void print_answer() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 'S') {
                cout << dist[r][c];
                return;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    make_dist();
    print_answer();
}
