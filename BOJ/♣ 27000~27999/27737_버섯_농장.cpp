#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Loc {
    int r, c;
};

int grid[101][101];
bool visited[101][101];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
vector<int> areas;
int N, M, K;

void bfs(int start_r, int start_c) {
    if (grid[start_r][start_c] == 1 || visited[start_r][start_c]) {
        return;
    }

    queue<Loc> q;
    q.push({start_r, start_c});
    visited[start_r][start_c] = true;
    int area_size = 0;

    while (!q.empty()) {
        Loc cur = q.front();
        q.pop();

        area_size += 1;

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > N || c < 1 || c > N || visited[r][c] || grid[r][c] == 1) {
                continue;
            }

            q.push({r, c});
            visited[r][c] = true;
        }
    }

    areas.push_back(area_size);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> K;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> grid[r][c];
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            bfs(r, c);
        }
    }

    int remain = M;

    for (size_t i = 0; i < areas.size(); i++) {
        remain -= areas[i] / K;

        if (areas[i] % K != 0) {
            remain -= 1;
        }
    }

    if (remain >= 0 && remain != M) {
        cout << "POSSIBLE\n"
             << remain;
    } else {
        cout << "IMPOSSIBLE";
    }
}