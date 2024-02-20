#include <algorithm>
#include <iostream>
#include <queue>
#define INF 98'765'432
using namespace std;

struct Pos {
    int r, c, d;
};

char grid[12][12];
bool visited[11][11];
int result[11][11];
int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int R, C;

int get_floor_value(int num, int div) {
    int value = num / div;

    if (num % div > 0) {
        value += 1;
    }

    return value;
}

void traverse(int start_r, int start_c, int power) {
    fill(&visited[1][1], &visited[R][C + 1], false);
    visited[start_r][start_c] = true;
    queue<Pos> q;
    q.push({start_r, start_c, 0});

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        for (size_t i = 0; i < 8; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || visited[r][c]) {
                continue;
            }

            visited[r][c] = true;
            q.push({r, c, cur.d + 1});

            if (result[r][c] != INF) {
                result[r][c] += get_floor_value(cur.d + 1, power);
            }
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (!visited[r][c]) {
                result[r][c] = INF;
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

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] != '.') {
                traverse(r, c, grid[r][c] - '0');
            }
        }
    }

    int answer = INF;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            answer = min(answer, result[r][c]);
        }
    }

    if (answer == INF) {
        cout << -1;
    } else {
        cout << answer;
    }
}
