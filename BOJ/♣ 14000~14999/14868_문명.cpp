#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct loc {
    int r, c, d, t;
};

int parent[100001];
int grid[2001][2001];
bool visited[2001][2001];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
queue<loc> q;
int N, K;

int get_parent(int child) {
    if (parent[child] == 0)
        return child;

    return parent[child] = get_parent(parent[child]);
}

void merge(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a != b) {
        parent[a] = b;
        K--;
    }
}

void scan(int cur_r, int cur_c, int team) {
    for (int i = 0; i < 4; i++) {
        int r = cur_r + dr[i];
        int c = cur_c + dc[i];

        if (r >= 1 && r <= N && c >= 1 && c <= N && grid[r][c] != 0)
            merge(team, grid[r][c]);
    }
}

int bfs() {
    while (true) {
        loc cur = q.front();
        q.pop();

        grid[cur.r][cur.c] = cur.t;
        scan(cur.r, cur.c, cur.t);

        if (K == 1)
            return cur.d;

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r >= 1 && r <= N && c >= 1 && c <= N && !visited[r][c]) {
                q.push({r, c, cur.d + 1, cur.t});
                visited[r][c] = true;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;

    for (int i = 1; i <= K; i++) {
        int r, c;
        cin >> r >> c;
        grid[r][c] = i;
        q.push({r, c, 0, i});
        visited[r][c] = true;
    }

    cout << bfs();
}