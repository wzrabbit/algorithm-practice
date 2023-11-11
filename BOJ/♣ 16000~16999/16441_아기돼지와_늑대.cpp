#include <iostream>
#include <queue>
using namespace std;

struct Pos {
    int r, c;
};

char grid[102][102];
bool visited[102][102];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;

Pos get_next_position(Pos cur, int direction) {
    int r = cur.r;
    int c = cur.c;

    for (int i = 1; i <= 1000; i++) {
        int next_r = r + dr[direction];
        int next_c = c + dc[direction];

        if (next_r < 1 || next_r > R || next_c < 1 || next_c > C || grid[next_r][next_c] == '#') {
            return {r, c};
        }

        if (grid[next_r][next_c] != '+') {
            return {next_r, next_c};
        }

        r = next_r;
        c = next_c;
    }

    return {-1, -1};
}

void print_result() {
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == '.' && !visited[r][c]) {
                cout << 'P';
                continue;
            }

            cout << grid[r][c];
        }

        cout << '\n';
    }
}

void bfs() {
    queue<Pos> q;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 'W') {
                visited[r][c] = true;
                q.push({r, c});
            }
        }
    }

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            Pos next_pos = get_next_position(cur, i);

            if (!visited[next_pos.r][next_pos.c]) {
                visited[next_pos.r][next_pos.c] = true;
                q.push({next_pos.r, next_pos.c});
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

    bfs();
    print_result();
}