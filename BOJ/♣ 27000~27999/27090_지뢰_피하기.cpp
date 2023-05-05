#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 1234567
using namespace std;

struct Loc {
    int r, c, l;
};

bool operator<(Loc a, Loc b) {
    return a.l < b.l;
}

int grid[1001][1001];
int limit[1001][1001];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dijkstra(int R, int C, int start_r, int start_c) {
    priority_queue<Loc> pq;
    pq.push({start_r, start_c, INF});
    limit[start_r][start_c] = INF;

    while (!pq.empty()) {
        Loc cur = pq.top();
        pq.pop();

        if (cur.l < limit[cur.r][cur.c]) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int r = cur.r + dr[i];
            int c = cur.c + dc[i];

            if (r < 1 || r > R || c < 1 || c > C) {
                continue;
            }

            int next_limit = min(cur.l, grid[r][c] < 0 ? INF : grid[r][c]);

            if (next_limit > limit[r][c]) {
                limit[r][c] = next_limit;
                pq.push({r, c, next_limit});
            }
        }
    }
}

void print_answer(int R, int C) {
    vector<int> item_costs;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == -2) {
                item_costs.push_back(limit[r][c]);
            }
        }
    }

    sort(item_costs.begin(), item_costs.end());

    int item_count = 0;

    for (size_t i = 0; i < item_costs.size(); i++) {
        if (item_count + 1 < item_costs[i]) {
            item_count += 1;
        }
    }

    cout << item_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C, start_r, start_c;
    cin >> R >> C >> start_r >> start_c;

    fill(&grid[1][1], &grid[R][C + 1], -1);

    int K;
    cin >> K;

    for (int i = 1; i <= K; i++) {
        int r, c;
        cin >> r >> c;

        grid[r][c] = -2;
    }

    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        int r, c, l;
        cin >> r >> c >> l;

        grid[r][c] = l;
    }

    dijkstra(R, C, start_r, start_c);
    print_answer(R, C);
}