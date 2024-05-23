#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Loc {
    int m, r, c, d;
};

char grid[502][502];
bool visited[3][502][502];
int dr[3][4] = {{-3, 1, 0, 0}, {-1, 1, 0, 0}, {-1, 3, 0, 0}};
int dc[3][4] = {{0, 0, -3, 1}, {0, 0, -1, 3}, {0, 0, -1, 1}};
int dm[3][4] = {{2, 2, 1, 1}, {1, 1, 0, 0}, {0, 0, 2, 2}};
int R, C;
int start_r, start_c;
int end_r, end_c;

void assign_start_end_position() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == '2') {
                start_r = r;
                start_c = c;
            } else if (grid[r][c] == '3') {
                end_r = r;
                end_c = c;
            }
        }
    }
}

bool is_finished(int m, int r, int c) {
    if (m == 1) {
        return grid[r][c] == '3' ||
               grid[r][c + 1] == '3' ||
               grid[r][c + 2] == '3';
    }

    if (m == 2) {
        return grid[r][c] == '3' ||
               grid[r + 1][c] == '3' ||
               grid[r + 2][c] == '3';
    }

    return grid[r][c] == '3';
}

bool is_safe_place(int m, int r, int c) {
    if (r < 1 || r > R || c < 1 || c > C) {
        return false;
    }

    if (m == 0) {
        return grid[r][c] != '0';
    }

    if (m == 1 && c + 2 > C) {
        return false;
    }

    if (m == 2 && r + 2 > R) {
        return false;
    }

    if (m == 1) {
        return (grid[r][c + 1] != '0') |
               (grid[r][c] != '0' && grid[r][c + 2] != '0');
    }

    return (grid[r + 1][c] != '0') |
           (grid[r][c] != '0' && grid[r + 2][c] != '0');
}

int get_move_count() {
    queue<Loc> q;
    q.push({0, start_r, start_c, 0});
    visited[0][start_r][start_c] = true;

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();

        if (is_finished(cur.m, cur.r, cur.c)) {
            return cur.d;
        }

        for (int i = 0; i < 4; i++) {
            int m = dm[cur.m][i];
            int r = cur.r + dr[cur.m][i];
            int c = cur.c + dc[cur.m][i];
            int d = cur.d + 1;

            if (is_safe_place(m, r, c) && !visited[m][r][c]) {
                visited[m][r][c] = true;
                q.push({m, r, c, d});
            }
        }
    }

    return -2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    assign_start_end_position();

    cout << get_move_count();
}
