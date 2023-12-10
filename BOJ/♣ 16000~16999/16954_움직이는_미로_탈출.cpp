#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Pos {
    int l, r, c;
};

char grid[9][10][10];
bool visited[9][9][9];
int dr[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dc[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

bool can_escape() {
    queue<Pos> q;
    q.push({0, 8, 1});
    visited[0][8][1] = true;

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        if (cur.l == 8) {
            return true;
        }

        for (int i = 0; i < 9; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > 8 || c < 1 || c > 8 || visited[cur.l + 1][r][c]) {
                continue;
            }

            if (grid[cur.l][r][c] == '.' && grid[cur.l + 1][r][c] == '.') {
                q.push({cur.l + 1, r, c});
                visited[cur.l + 1][r][c] = true;
            }
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int r = 1; r <= 8; r++) {
        cin >> (grid[0][r] + 1);
    }

    for (int i = 1; i <= 8; i++) {
        for (int r = 1; r <= i; r++) {
            for (int c = 1; c <= 8; c++) {
                grid[i][r][c] = '.';
            }
        }

        for (int r = i + 1; r <= 8; r++) {
            for (int c = 1; c <= 8; c++) {
                grid[i][r][c] = grid[i - 1][r - 1][c];
            }
        }
    }

    cout << can_escape();
}