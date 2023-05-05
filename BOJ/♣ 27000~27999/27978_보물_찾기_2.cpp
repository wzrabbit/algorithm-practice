#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

struct Loc {
    int r, c, d;
};

char grid[501][502];
bool visited[501][501];
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int get_minimum_fuel(int R, int C, int start_R, int start_C) {
    deque<Loc> q;
    q.push_back({start_R, start_C});

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop_front();

        if (visited[cur.r][cur.c]) {
            continue;
        }

        visited[cur.r][cur.c] = true;

        if (grid[cur.r][cur.c] == '*') {
            return cur.d;
        }

        for (int i = 0; i < 8; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || visited[r][c] || grid[r][c] == '#') {
                continue;
            }

            if (i >= 5) {
                q.push_front({r, c, cur.d});
            } else {
                q.push_back({r, c, cur.d + 1});
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    int start_R = 0;
    int start_C = 0;

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 'K') {
                start_R = r;
                start_C = c;
            }
        }
    }

    cout << get_minimum_fuel(R, C, start_R, start_C);
}