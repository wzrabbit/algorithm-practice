#include <iostream>
#include <queue>
using namespace std;

struct Loc {
    int r, c, n;
};

char grid[501][501];
int visited[500][500];
int R, C;
int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
queue<Loc> que;

void find_knights() {
    int no = 1;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (grid[r][c] == 'H') {
                que.push({r, c, no});
                visited[r][c] = no;
                no += 1;
            }
        }
    }
}

bool traverse_knights() {
    while (!que.empty()) {
        Loc cur = que.front();
        que.pop();

        for (int i = 0; i < 8; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (0 <= r && r < R && 0 <= c && c < C && grid[r][c] != '#' && visited[r][c] != cur.n) {
                if (visited[r][c] != 0) {
                    return true;
                }

                visited[r][c] = cur.n;
                que.push({r, c, cur.n});
            }
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 0; r < R; r++) {
        cin >> grid[r];
    }

    find_knights();
    bool is_success = traverse_knights();

    if (is_success) {
        cout << "JA";
    } else {
        cout << "NEJ";
    }
}