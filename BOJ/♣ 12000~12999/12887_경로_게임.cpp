#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Loc {
    int r, c, d;
};

char grid[3][52];
bool visited[3][52];
int dr[3] = {-1, 1, 0};
int dc[4] = {0, 0, 1};
int R = 2;
int C;

int get_empty_cell_count() {
    int empty_cell_count = 0;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == '.') {
                empty_cell_count += 1;
            }
        }
    }

    return empty_cell_count;
}

int get_required_cell_count_to_cross() {
    queue<Loc> q;

    if (grid[1][1] == '.') {
        q.push({1, 1, 1});
    }

    if (grid[2][1] == '.') {
        q.push({2, 1, 1});
    }

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();

        if (cur.c == C) {
            return cur.d;
        }

        for (int i = 0; i < 3; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r >= 1 && r <= R && c <= C && grid[r][c] == '.' && !visited[r][c]) {
                q.push({r, c, cur.d + 1});
                visited[r][c] = true;
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> C;

    for (int r = 1; r <= 2; r++) {
        cin >> (grid[r] + 1);
    }

    int empty_cell_count = get_empty_cell_count();
    int required_cell_count = get_required_cell_count_to_cross();

    cout << empty_cell_count - required_cell_count;
}
