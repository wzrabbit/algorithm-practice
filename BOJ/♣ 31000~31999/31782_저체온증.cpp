#include <algorithm>
#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

struct Pos {
    int r, c;
};

int R, C, P;
char grid[2001][2001];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
vector<Pos> rectangle_sizes;

int get_adj_count(int cur_r, int cur_c) {
    int adj_count = 0;

    for (int i = 0; i < 4; i++) {
        int r = cur_r + dr[i];
        int c = cur_c + dc[i];

        if (r < 1 || r > R || c < 1 || c > C) {
            continue;
        }

        if (grid[r][c] == 'O') {
            adj_count += 1;
        }
    }

    return adj_count;
}

void make_init_state() {
    queue<Pos> q;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 'O') {
                q.push({r, c});
            }
        }
    }

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || grid[r][c] == 'O') {
                continue;
            }

            int adj_count = get_adj_count(r, c);

            if (adj_count >= 2) {
                grid[r][c] = 'O';
                q.push({r, c});
            }
        }
    }
}

void generate_rectangle_size(int start_r, int start_c) {
    int row_count = 0;
    int col_count = 0;

    for (int r = start_r; r <= R; r++) {
        if (grid[r][start_c] == 'O') {
            row_count += 1;
        } else {
            break;
        }
    }

    for (int c = start_c; c <= C; c++) {
        if (grid[start_r][c] == 'O') {
            col_count += 1;
        } else {
            break;
        }
    }

    for (int r = start_r; r < start_r + row_count; r++) {
        for (int c = start_c; c < start_c + col_count; c++) {
            grid[r][c] = '.';
        }
    }

    rectangle_sizes.push_back({row_count, col_count});
}

void generate_rectangle_sizes() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 'O') {
                generate_rectangle_size(r, c);
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> P;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    make_init_state();
    generate_rectangle_sizes();

    int answer = 0;

    for (size_t i = 0; i < rectangle_sizes.size(); i++) {
        Pos cur = rectangle_sizes[i];

        if (cur.r > P && cur.c > P) {
            answer += cur.r * cur.c;
        }
    }

    cout << answer;
}
