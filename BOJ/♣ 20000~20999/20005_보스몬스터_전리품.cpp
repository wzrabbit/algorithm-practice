#include <algorithm>
#include <iostream>
#include <queue>
#define INF 12'345'678
using namespace std;

struct Pos {
    int r, c, d;
};

char grid[1002][1002];
bool visited[1002][1002];
int dist[26];
int damage[26];
bool arrived[26];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C, P;

void bfs(int start_r, int start_c) {
    queue<Pos> q;
    visited[start_r][start_c] = true;
    q.push({start_r, start_c, 0});

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        if (grid[cur.r][cur.c] >= 'a' && grid[cur.r][cur.c] <= 'z') {
            dist[grid[cur.r][cur.c] - 'a'] = cur.d;
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || visited[r][c] || grid[r][c] == 'X') {
                continue;
            }

            visited[r][c] = true;
            q.push({r, c, cur.d + 1});
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> P;
    int start_r = -1;
    int start_c = -1;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);

        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == 'B') {
                start_r = r;
                start_c = c;
            }
        }
    }

    fill(dist, dist + 26, INF);

    for (int i = 1; i <= P; i++) {
        char c;
        int d;
        cin >> c >> d;

        damage[c - 'a'] = d;
    }

    bfs(start_r, start_c);

    int boss_hp;
    cin >> boss_hp;

    int cur_time = 1;

    while (boss_hp > 0) {
        for (int i = 0; i < 26; i++) {
            if (dist[i] <= cur_time) {
                arrived[i] = true;
                boss_hp -= damage[i];
            }
        }

        cur_time += 1;
    }

    int arrived_count = 0;

    for (int i = 0; i < 26; i++) {
        if (arrived[i]) {
            arrived_count += 1;
        }
    }

    cout << arrived_count;
}