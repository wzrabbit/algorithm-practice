#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int t, r, c;
};

bool visited[2][501][501];
int dr[2][8];
int dc[2][8];
int N, a, b, c, d;

int get_visited_count() {
    queue<Node> q;
    q.push({0, 1, 1});
    q.push({1, 1, 1});
    visited[0][1][1] = true;
    visited[1][1][1] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int t = !cur.t;
            int r = cur.r + dr[cur.t][i];
            int c = cur.c + dc[cur.t][i];

            if (r >= 1 && r <= N && c >= 1 && c <= N && !visited[t][r][c]) {
                visited[t][r][c] = true;
                q.push({t, r, c});
            }
        }
    }

    int visited_count = 0;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (visited[0][r][c] || visited[1][r][c]) {
                visited_count += 1;
            }
        }
    }

    return visited_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> a >> b >> c >> d;

    dr[0][0] = a;
    dc[0][0] = b;
    dr[0][1] = a;
    dc[0][1] = -b;
    dr[0][2] = -a;
    dc[0][2] = b;
    dr[0][3] = -a;
    dc[0][3] = -b;
    dr[0][4] = b;
    dc[0][4] = a;
    dr[0][5] = b;
    dc[0][5] = -a;
    dr[0][6] = -b;
    dc[0][6] = a;
    dr[0][7] = -b;
    dc[0][7] = -a;

    dr[1][0] = c;
    dc[1][0] = d;
    dr[1][1] = c;
    dc[1][1] = -d;
    dr[1][2] = -c;
    dc[1][2] = d;
    dr[1][3] = -c;
    dc[1][3] = -d;
    dr[1][4] = d;
    dc[1][4] = c;
    dr[1][5] = d;
    dc[1][5] = -c;
    dr[1][6] = -d;
    dc[1][6] = c;
    dr[1][7] = -d;
    dc[1][7] = -c;

    cout << get_visited_count();
}
