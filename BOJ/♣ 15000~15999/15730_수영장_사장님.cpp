#include <algorithm>
#include <iostream>
#include <queue>
#define INF 12'345
using namespace std;

struct Pos {
    int r, c, w;
};

bool operator<(const Pos& a, const Pos& b) {
    return a.w > b.w;
}

int height[103][103];
int water[103][103];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C;

void settle_water() {
    priority_queue<Pos> pq;

    for (int r = 1; r <= R; r++) {
        water[r][1] = 0;
        water[r][C] = 0;
        pq.push({r, 1, 0});
        pq.push({r, C, 0});
    }

    for (int c = 2; c <= C - 1; c++) {
        water[1][c] = 0;
        water[R][c] = 0;
        pq.push({1, c, 0});
        pq.push({R, c, 0});
    }

    while (!pq.empty()) {
        Pos cur = pq.top();
        pq.pop();

        if (cur.w > water[cur.r][cur.c]) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C) {
                continue;
            }

            int w = max(cur.w, height[r][c]);

            if (w < water[r][c]) {
                water[r][c] = w;
                pq.push({r, c, w});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    R += 2;
    C += 2;

    for (int r = 2; r <= R - 1; r++) {
        for (int c = 2; c <= C - 1; c++) {
            cin >> height[r][c];
        }
    }

    fill(&water[1][1], &water[R][C + 1], INF);

    settle_water();

    int water_amount = 0;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            water_amount += water[r][c] - height[r][c];
        }
    }

    cout << water_amount;
}