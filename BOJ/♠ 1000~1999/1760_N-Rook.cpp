#include <iostream>
#include <vector>
using namespace std;

int left_values[5001], right_values[5001];
int grid[101][101];
int horizontal[101][101], vertical[101][101];
bool visited[5001];
vector<int> graph[5001];
int R, C, left_count;

void make_graph() {
    int id = 1;
    bool activated = false;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 0) {
                horizontal[r][c] = id;
                activated = true;
            }

            if (grid[r][c] == 2 && activated) {
                id += 1;
                activated = false;
            }
        }

        if (activated) {
            id += 1;
            activated = false;
        }
    }

    left_count = id - 1;

    id = 1;
    activated = false;

    for (int c = 1; c <= C; c++) {
        for (int r = 1; r <= R; r++) {
            if (grid[r][c] == 0) {
                vertical[r][c] = id;
                activated = true;
            }

            if (grid[r][c] == 2 && activated) {
                id += 1;
                activated = false;
            }
        }

        if (activated) {
            id += 1;
            activated = false;
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 0 && horizontal[r][c] != 0 &&
                vertical[r][c] != 0) {
                graph[horizontal[r][c]].push_back(vertical[r][c]);
            }
        }
    }
}

bool dfs(int cur) {
    if (visited[cur]) {
        return false;
    }

    visited[cur] = true;

    for (int adj : graph[cur]) {
        if (!right_values[adj] || dfs(right_values[adj])) {
            left_values[cur] = adj;
            right_values[adj] = cur;
            return true;
        }
    }

    return false;
}

int get_matched_count() {
    int matched_count = 0;

    for (int i = 1; i <= left_count; i++) {
        fill(visited + 1, visited + left_count + 1, false);

        if (dfs(i)) {
            matched_count += 1;
        }
    }

    return matched_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    make_graph();

    cout << get_matched_count();
}
