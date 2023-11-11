#include <iostream>
#include <queue>
using namespace std;

struct Pos {
    int r, c;
};

char grid[102][102];
int visited[102][102];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;

void paint(int start_r, int start_c, int color) {
    if (visited[start_r][start_c] != 0 || grid[start_r][start_c] == '.') {
        return;
    }

    queue<Pos> q;
    q.push({start_r, start_c});
    visited[start_r][start_c] = color;

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || visited[r][c] != 0 || grid[r][c] == '.') {
                continue;
            }

            visited[r][c] = color;
            q.push({r, c});
        }
    }
}

void mark_cluster(int target_row, int direction) {
    if (direction == 1) {
        for (int c = 1; c <= C; c++) {
            if (grid[target_row][c] == 'x') {
                grid[target_row][c] = '.';
                break;
            }
        }
    } else {
        for (int c = C; c >= 1; c--) {
            if (grid[target_row][c] == 'x') {
                grid[target_row][c] = '.';
                break;
            }
        }
    }

    fill(&visited[1][1], &visited[R][C + 1], 0);

    for (int c = 1; c <= C; c++) {
        paint(R, c, -1);
    }

    for (int r = 1; r <= R - 1; r++) {
        for (int c = 1; c <= C; c++) {
            paint(r, c, 1);
        }
    }
}

int get_fall_height() {
    int min_height = R;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (visited[r][c] != 1) {
                continue;
            }

            int cur_r = r + 1;
            bool skip = false;

            while (cur_r <= R) {
                if (visited[cur_r][c] == 1) {
                    skip = true;
                    break;
                }

                if (grid[cur_r][c] == 'x') {
                    break;
                }

                cur_r += 1;
            }

            if (!skip) {
                min_height = min(min_height, cur_r - r - 1);
            }
        }
    }

    return min_height;
}

void fall_cluster(int fall_height) {
    for (int r = R; r >= 1; r--) {
        for (int c = 1; c <= C; c++) {
            if (visited[r][c] == 1) {
                grid[r][c] = '.';
                grid[r + fall_height][c] = 'x';
            }
        }
    }
}

void perform(int target_height, int direction) {
    int target_row = R + 1 - target_height;

    mark_cluster(target_row, direction);
    int fall_height = get_fall_height();
    fall_cluster(fall_height);
}

void print_result() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cout << grid[r][c];
        }

        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    int Q;
    cin >> Q;

    for (int i = 1; i <= Q; i++) {
        int cur;
        cin >> cur;

        perform(cur, i % 2);
    }

    print_result();
}