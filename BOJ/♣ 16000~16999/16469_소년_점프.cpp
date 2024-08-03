#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <queue>
#include <string>
#define INF 98765
using namespace std;

struct Loc {
    int r, c;
};

char grid[102][102];
int dist[3][102][102];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;

void write_dist(int start_r, int start_c, int dist[102][102]) {
    queue<Loc> q;
    q.push({start_r, start_c});
    fill(&dist[1][1], &dist[R][C + 1], INF);
    dist[start_r][start_c] = 0;

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || dist[r][c] != INF || grid[r][c] == '1') {
                continue;
            }

            dist[r][c] = dist[cur.r][cur.c] + 1;
            q.push({r, c});
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    for (int i = 0; i < 3; i++) {
        int r, c;
        cin >> r >> c;

        write_dist(r, c, dist[i]);
    }

    int answer = INF;
    int answer_count = 0;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            int cur_answer = max({dist[0][r][c], dist[1][r][c], dist[2][r][c]});

            if (cur_answer < answer) {
                answer = cur_answer;
                answer_count = 1;
            } else if (cur_answer == answer) {
                answer_count += 1;
            }
        }
    }

    if (answer == INF) {
        cout << -1;
    } else {
        cout << answer << '\n'
             << answer_count;
    }
}
