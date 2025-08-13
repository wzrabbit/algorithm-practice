#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int r, c, d;
};

char grid[502][502];
bool visited[502][502];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;

int get_dist() {
    queue<Node> q;
    q.push({1, 1, 0});

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.r == R && cur.c == C) {
            return cur.d;
        }
        
        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i] * (grid[cur.r][cur.c] - '0');
            int c = cur.c + dc[i] * (grid[cur.r][cur.c] - '0');

            if (r < 1 || r > R || c < 1 || c > C || visited[r][c]) {
                continue;
            }

            visited[r][c] = true;
            q.push({r, c, cur.d + 1});
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        cin >> (grid[r] + 1);
    }

    int dist = get_dist();

    if (dist == -1) {
        cout << "IMPOSSIBLE";
    } else {
        cout << dist;
    }
}
