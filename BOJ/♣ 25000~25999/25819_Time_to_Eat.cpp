#include <algorithm>
#include <iostream>
#include <queue>
#define INF 100000
using namespace std;

struct loc {
    int r, c;
};

struct pq_loc {
    int r, c, d;
};

bool operator<(pq_loc a, pq_loc b) {
    return a.d > b.d;
}

int dist[52][52];
vector<loc> loc_list;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C, F, S;
    cin >> R >> C >> F >> S;

    for (int i = 0; i < S; i++) {
        int r, c;
        cin >> r >> c;
        loc_list.push_back({r, c});
    }
    loc_list.push_back({R, C});

    priority_queue<pq_loc> pq;
    pq.push({1, 1, 0});
    fill(&dist[1][1], &dist[R][C + 1], INF);
    dist[1][1] = 0;

    while (pq.size()) {
        pq_loc cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.r][cur.c]) continue;

        for (size_t i = 0; i <= S; i++) {
            loc nxt = loc_list[i];
            int nxt_dist = abs(cur.r - nxt.r) + abs(cur.c - nxt.c);
            if (cur.d + nxt_dist < dist[nxt.r][nxt.c] && nxt_dist <= F) {
                dist[nxt.r][nxt.c] = cur.d + nxt_dist;
                pq.push({nxt.r, nxt.c, cur.d + nxt_dist});
            }
        }
    }

    cout << dist[R][C];
}