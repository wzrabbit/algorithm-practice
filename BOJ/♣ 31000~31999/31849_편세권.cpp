#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

struct Room {
    int r, c, p;
};

struct QData {
    int r, c, d;
};

int dist[1001][1001];
vector<Room> rooms;
queue<QData> q;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C, A, B;

void make_dist() {
    while (!q.empty()) {
        QData cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || dist[r][c] != -1) {
                continue;
            }

            q.push({r, c, cur.d + 1});
            dist[r][c] = cur.d + 1;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> A >> B;

    fill(&dist[1][1], &dist[R][C + 1], -1);

    for (int i = 1; i <= A; i++) {
        int r, c, p;
        cin >> r >> c >> p;

        rooms.push_back({r, c, p});
    }

    for (int i = 1; i <= B; i++) {
        int r, c;
        cin >> r >> c;

        q.push({r, c, 0});
        dist[r][c] = 0;
    }

    make_dist();

    int answer = INF;

    for (int i = 0; i < A; i++) {
        Room cur = rooms[i];
        answer = min(answer, dist[cur.r][cur.c] * cur.p);
    }

    cout << answer;
}
