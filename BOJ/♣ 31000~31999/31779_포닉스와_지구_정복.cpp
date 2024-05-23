#include <algorithm>
#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

struct Pos {
    int r, c;
};

int R, C, B;
ll grid[1001][1001];
ll goal[1001][1001];
bool has_bomb[1001][1001];
bool visited[1001][1001];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool check_area(int start_r, int start_c) {
    ll even_total = 0;
    ll odd_total = 0;
    ll goal_even_total = 0;
    ll goal_odd_total = 0;

    queue<Pos> q;
    q.push({start_r, start_c});
    visited[start_r][start_c] = true;

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        if ((cur.r + cur.c) % 2 == 0) {
            even_total += grid[cur.r][cur.c];
            goal_even_total += goal[cur.r][cur.c];
        } else {
            odd_total += grid[cur.r][cur.c];
            goal_odd_total += goal[cur.r][cur.c];
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || visited[r][c] || has_bomb[r][c]) {
                continue;
            }

            visited[r][c] = true;
            q.push({r, c});
        }
    }

    return odd_total - even_total == goal_odd_total - goal_even_total;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> B;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> goal[r][c];
        }
    }

    for (int i = 1; i <= B; i++) {
        int r, c;
        cin >> r >> c;

        has_bomb[r][c] = true;

        if (grid[r][c] != goal[r][c]) {
            cout << "No";
            return 0;
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (visited[r][c]) {
                continue;
            }

            bool result = check_area(r, c);

            if (!result) {
                cout << "No";
                return 0;
            }
        }
    }

    cout << "Yes";
}
