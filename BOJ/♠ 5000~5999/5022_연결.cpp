#include <algorithm>
#include <iostream>
#include <queue>
#define INF 100'000'000
using namespace std;

struct Pos {
    int r, c;
};

int dist[101][101];
Pos history[101][101];
bool filled[101][101];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
Pos A1, A2, B1, B2;
int R, C;

void draw_history(Pos start) {
    Pos cur = start;

    while (cur.r != -1 && cur.c != -1) {
        filled[cur.r][cur.c] = true;
        cur = history[cur.r][cur.c];
    }
}

int draw_and_get_dist(Pos start, Pos end, Pos ban1, Pos ban2) {
    fill(&dist[0][0], &dist[R][C + 1], INF);
    fill(&history[0][0], &history[R][C + 1], Pos{-1, -1});
    dist[ban1.r][ban1.c] = 0;
    dist[ban2.r][ban2.c] = 0;
    dist[start.r][start.c] = 0;
    queue<Pos> q;
    q.push({start.r, start.c});
    history[start.r][start.c] = {-1, -1};

    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        if (cur.r == end.r && cur.c == end.c) {
            draw_history(end);
            return dist[end.r][end.c];
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 0 || r > R || c < 0 || c > C || dist[r][c] != INF || filled[r][c]) {
                continue;
            }

            dist[r][c] = dist[cur.r][cur.c] + 1;
            history[r][c] = {cur.r, cur.c};
            q.push({r, c});
        }
    }

    return INF;
}

int main() {
    cin >> R >> C;
    cin >> A1.r >> A1.c >> A2.r >> A2.c >> B1.r >> B1.c >> B2.r >> B2.c;

    int answer = INF;

    int A_dist = draw_and_get_dist(A1, A2, B1, B2);
    int B_dist = draw_and_get_dist(B1, B2, A1, A2);

    answer = min(answer, A_dist + B_dist);

    fill(&filled[0][0], &filled[R][C + 1], false);

    B_dist = draw_and_get_dist(B1, B2, A1, A2);
    A_dist = draw_and_get_dist(A1, A2, B1, B2);

    answer = min(answer, B_dist + A_dist);

    if (answer == INF) {
        cout << "IMPOSSIBLE";
    } else {
        cout << answer;
    }
}
