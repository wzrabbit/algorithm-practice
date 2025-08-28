#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1'000'000'000
using namespace std;

struct Node {
    int r, c, d;
};

bool operator<(const Node &a, const Node &b) {
    return a.d > b.d;
}

struct Intersection {
    char s;
    int h, v;
};

char grid[22][22];
int dist[22][22];
Intersection intersections[10];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int R, C, K, start_R, start_C;

int get_next_open_time(int intersection_no, int cur_time, char direction) {
    Intersection &in = intersections[intersection_no];
    int cycle = in.h + in.v;
    int remainder = cur_time % cycle;

    if (
        (in.s == '-' && direction == '-' && remainder < in.h) ||
        (in.s == '-' && direction == '|' && remainder >= in.h) ||
        (in.s == '|' && direction == '-' && remainder >= in.v) ||
        (in.s == '|' && direction == '|' && remainder < in.v)
    ) {
        return cur_time + 1;
    }

    if (in.s == '-' && direction == '|') {
        return cur_time - remainder + in.h + 1;
    }

    if (in.s == '|' && direction == '-') {
        return cur_time - remainder + in.v + 1;
    }

    return cur_time + cycle - remainder + 1;
}

int get_dist() {
    priority_queue<Node> pq;
    pq.push({start_R, start_C, 0});
    fill(&dist[1][1], &dist[R][C + 1], INF);
    dist[start_R][start_C] = 0;

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.r][cur.c]) {
            continue;
        }

        if (grid[cur.r][cur.c] == 'B') {
            return cur.d;
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C || grid[r][c] == '.') {
                continue;
            }

            int d = cur.d + 1;
            char direction = (i < 2) ? '|' : '-';

            if (grid[r][c] >= '0' && grid[r][c] <= '9') {
                d = get_next_open_time(grid[r][c] - '0', cur.d, direction);
            }

            if (d < dist[r][c]) {
                dist[r][c] = d;
                pq.push({r, c, d});
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    while (true) {
        cin >> R >> C;
        K = 0;
        start_R = 1;
        start_C = 1;

        if (R == 0 && C == 0) {
            break;
        }

        for (int r = 1; r <= R; r++) {
            cin >> (grid[r] + 1);

            for (int c = 1; c <= C; c++) {
                if (grid[r][c] >= '0' && grid[r][c] <= '9') {
                    K = max(K, grid[r][c] - '0' + 1);
                }

                if (grid[r][c] == 'A') {
                    start_R = r;
                    start_C = c;
                }
            }
        }

        for (int i = 1; i <= K; i++) {
            int no;
            cin >> no;
            cin >> intersections[no].s >> intersections[no].h >> intersections[no].v;
        }

        int answer = get_dist();
        
        if (answer == -1) {
            cout << "impossible\n";
        } else {
            cout << answer << '\n';
        }
    }
}
