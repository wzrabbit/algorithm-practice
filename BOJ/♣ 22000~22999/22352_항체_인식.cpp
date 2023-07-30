#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Loc {
    int r, c;
};

int before[31][31];
int after[31][31];
bool visited[31][31];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;

bool is_same_board() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (before[r][c] != after[r][c]) {
                return false;
            }
        }
    }

    return true;
}

void bfs(int start_r, int start_c, int before_value, int after_value) {
    queue<Loc> q;
    q.push({start_r, start_c});
    visited[start_r][start_c] = true;
    before[start_r][start_c] = after_value;

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || visited[r][c] || before[r][c] != before_value) continue;

            visited[r][c] = true;
            before[r][c] = after_value;
            q.push({r, c});
        }
    }
}

void find_different_node() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (before[r][c] != after[r][c]) {
                bfs(r, c, before[r][c], after[r][c]);
                return;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> before[r][c];
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> after[r][c];
        }
    }

    find_different_node();

    if (is_same_board()) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}