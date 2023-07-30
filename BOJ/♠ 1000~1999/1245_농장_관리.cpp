#include <iostream>
#include <queue>
using namespace std;

struct Loc {
    int r, c;
};

int grid[101][71];
bool visited[101][71];
int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {0, 1, -1, 1, -1, 0, -1, 1};
int R, C;
int peak_count = 0;

void traverse(int start_R, int start_C) {
    if (visited[start_R][start_C]) {
        return;
    }

    queue<Loc> q;
    q.push({start_R, start_C});
    visited[start_R][start_C] = true;
    bool is_peak = true;
    int cur_height = grid[start_R][start_C];

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C) {
                continue;
            }

            if (grid[r][c] > cur_height) {
                is_peak = false;
            }

            if (grid[r][c] == cur_height && !visited[r][c]) {
                visited[r][c] = true;
                q.push({r, c});
            }
        }
    }

    if (is_peak) {
        peak_count += 1;
    }
}

int main() {
    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            traverse(r, c);
        }
    }

    cout << peak_count;
}