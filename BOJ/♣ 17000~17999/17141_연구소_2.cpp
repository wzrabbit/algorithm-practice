#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 1'234'567
using namespace std;

struct Loc {
    int r, c;
};

int grid[51][51];
int dist[51][51];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
vector<Loc> virus_locations;
vector<int> selected_viruses;
int best_time = INF;
int N, M;
int virus_count;

int get_spread_time() {
    fill(&dist[1][1], &dist[N][N + 1], INF);
    queue<Loc> q;

    for (int i = 0; i < M; i++) {
        Loc cur = virus_locations[selected_viruses[i]];

        dist[cur.r][cur.c] = 0;
        q.push({cur.r, cur.c});
    }

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > N || c < 1 || c > N || grid[r][c] == 1 || dist[r][c] != INF) {
                continue;
            }

            dist[r][c] = dist[cur.r][cur.c] + 1;
            q.push({r, c});
        }
    }

    int max_dist = 0;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (dist[r][c] == INF) {
                if (grid[r][c] == 1) {
                    continue;
                } else {
                    return INF;
                }
            }

            max_dist = max(max_dist, dist[r][c]);
        }
    }

    return max_dist;
}

void make_sets(int selected_count, int previous) {
    if (selected_count == M) {
        best_time = min(best_time, get_spread_time());
        return;
    }

    for (int i = previous + 1; i <= virus_count - (M - selected_count); i++) {
        selected_viruses.push_back(i);
        make_sets(selected_count + 1, i);
        selected_viruses.pop_back();
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> grid[r][c];

            if (grid[r][c] == 2) {
                virus_locations.push_back({r, c});
            }
        }
    }

    virus_count = virus_locations.size();

    make_sets(0, -1);

    if (best_time < INF) {
        cout << best_time;
    } else {
        cout << -1;
    }
}