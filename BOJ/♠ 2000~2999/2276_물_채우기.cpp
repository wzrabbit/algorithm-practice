#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Loc {
    int r, c, h;
};

bool operator<(const Loc a, Loc b) {
    return a.h > b.h;
}

int pool[302][302];
int water[302][302];
bool visited[302][302];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int C, R;

void dijkstra() {
    priority_queue<Loc> pq;

    for (int r = 0; r < R; r++) {
        pq.push({r, 0, pool[r][0]});
        pq.push({r, C - 1, pool[r][C - 1]});
        water[r][0] = pool[r][0];
        water[r][C - 1] = pool[r][C - 1];
        visited[r][0] = true;
        visited[r][C - 1] = true;
    }

    for (int c = 1; c < R - 1; c++) {
        pq.push({1, c, pool[1][c]});
        pq.push({R - 2, c, pool[R - 2][c]});
        water[1][c] = pool[1][c];
        water[R - 2][c] = pool[R - 2][c];
        visited[1][c] = true;
        visited[R - 2][c] = true;
    }

    while (!pq.empty()) {
        Loc cur = pq.top();
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (0 <= r && r < R && 0 <= c && c < C && !visited[r][c]) {
                water[r][c] = max(pool[r][c], cur.h);
                visited[r][c] = true;
                pq.push({r, c, water[r][c]});
            }
        }
    }
}

int get_water_amount() {
    int result = 0;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (pool[r][c] < water[r][c]) {
                result += water[r][c] - pool[r][c];
            }
        }
    }

    return result;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> C >> R;
    R += 2;
    C += 2;

    for (int r = 1; r < R - 1; r++) {
        for (int c = 1; c < C - 1; c++) {
            cin >> pool[r][c];
        }
    }

    dijkstra();
    cout << get_water_amount() << '\n';
}