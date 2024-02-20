#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define INF 1'234'567'890
using namespace std;

struct Pos {
    int r, c;
};

vector<string> grid;
vector<vector<bool>> visited;
vector<vector<int>> dist;
vector<Pos> exits;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;

void traverse(Pos start) {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            visited[r][c] = false;
            dist[r][c] = INF;
        }
    }

    queue<Pos> q;
    q.push(start);
    visited[start.r][start.c] = true;
    dist[start.r][start.c] = 0;

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 0 || r >= R || c < 0 || c >= C || visited[r][c] || grid[r][c] == 'X') {
                continue;
            }

            visited[r][c] = true;
            dist[r][c] = dist[cur.r][cur.c] + 1;
            q.push({r, c});
        }
    }
}

int get_present_count(Pos exit) {
    traverse(exit);

    int hb_dist;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (grid[r][c] == 'H') {
                if (!visited[r][c]) {
                    return 0;
                }

                hb_dist = dist[r][c];
            }
        }
    }

    int present_count = 0;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (grid[r][c] == 'P' && visited[r][c] && dist[r][c] <= hb_dist) {
                present_count += 1;
            }
        }
    }

    return present_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    grid.resize(R);
    visited.resize(R, vector<bool>(C));
    dist.resize(R, vector<int>(C));

    for (int r = 0; r < R; r++) {
        cin >> grid[r];
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (grid[r][c] == '#') {
                exits.push_back({r, c});
            }
        }
    }

    int best_present_count = 0;

    for (size_t i = 0; i < exits.size(); i++) {
        best_present_count = max(best_present_count, get_present_count(exits[i]));
    }

    cout << best_present_count;
}
