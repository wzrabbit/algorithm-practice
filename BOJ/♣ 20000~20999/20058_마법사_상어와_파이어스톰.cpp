#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Pos {
    int r, c;
};

int grid[65][65];
bool visited[65][65];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int N, Q;

void spin_unit(int start_r, int start_c, int scale) {
    vector<int> saved;

    for (int c = start_c; c <= start_c + scale - 1; c++) {
        for (int r = start_r + scale - 1; r >= start_r; r--) {
            saved.push_back(grid[r][c]);
        }
    }

    int index = 0;

    for (int r = start_r; r <= start_r + scale - 1; r++) {
        for (int c = start_c; c <= start_c + scale - 1; c++) {
            grid[r][c] = saved[index++];
        }
    }
}

void spin(int level) {
    for (int r = 1; r <= N; r += (1 << level)) {
        for (int c = 1; c <= N; c += (1 << level)) {
            spin_unit(r, c, (1 << level));
        }
    }
}

void melt() {
    vector<int> saved;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            int ice_count = 0;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 1 || nr > N || nc < 1 || nc > N) {
                    continue;
                }

                if (grid[nr][nc] > 0) {
                    ice_count += 1;
                }
            }

            if (ice_count <= 2) {
                saved.push_back(max(grid[r][c] - 1, 0));
            } else {
                saved.push_back(grid[r][c]);
            }
        }
    }

    int index = 0;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            grid[r][c] = saved[index++];
        }
    }
}

int bfs(int start_r, int start_c) {
    queue<Pos> q;
    int graph_scale = 0;
    visited[start_r][start_c] = true;
    q.push({start_r, start_c});

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        graph_scale += 1;

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > N || c < 1 || c > N || visited[r][c] || grid[r][c] == 0) {
                continue;
            }

            visited[r][c] = true;
            q.push({r, c});
        }
    }

    return graph_scale;
}

int get_biggest_ice() {
    int biggest_ice = 0;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (!visited[r][c] && grid[r][c] > 0) {
                biggest_ice = max(biggest_ice, bfs(r, c));
            }
        }
    }

    return biggest_ice;
}

int get_ice_sum() {
    int total = 0;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            total += grid[r][c];
        }
    }

    return total;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> Q;

    N = (1 << N);

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> grid[r][c];
        }
    }

    while (Q--) {
        int cur_level;
        cin >> cur_level;

        spin(cur_level);
        melt();
    }

    cout << get_ice_sum() << '\n'
         << get_biggest_ice();
}