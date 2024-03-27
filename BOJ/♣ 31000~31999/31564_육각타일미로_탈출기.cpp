#include <algorithm>
#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

struct Pos {
    int r, c, d;
};

bool visited[1000][1000];
bool is_blocked[1000][1000];
int dr[6] = {-1, -1, 0, 1, 1, 0};
int dc[6] = {-1, 0, 1, 0, -1, -1};
int dc2[6] = {0, 1, 1, 1, 0, -1};
int R, C, B;

int get_dist() {
    queue<Pos> q;
    q.push({0, 0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        if (cur.r == R - 1 && cur.c == C - 1) {
            return cur.d;
        }

        for (int i = 0; i < 6; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];
            int d = cur.d + 1;

            if (cur.r % 2 == 1) {
                c = cur.c + dc2[i];
            }

            if (r < 0 || r >= R || c < 0 || c >= C || visited[r][c] || is_blocked[r][c]) {
                continue;
            }

            visited[r][c] = true;
            q.push({r, c, d});
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> B;

    for (int i = 1; i <= B; i++) {
        int r, c;
        cin >> r >> c;

        is_blocked[r][c] = true;
    }

    cout << get_dist();
}
