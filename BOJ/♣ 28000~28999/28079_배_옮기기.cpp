#include <algorithm>
#include <iostream>
#include <queue>
#define INF 98'765'432
using namespace std;

struct Loc {
    int b, r, d;
};

bool operator<(const Loc& a, const Loc& b) {
    return a.d > b.d;
}

int scale[15];
int bit[15];
int dist[32768][2];
int N;

void dijkstra() {
    priority_queue<Loc> pq;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        Loc cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.b][cur.r]) {
            continue;
        }

        if (cur.r == 0) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (!(cur.b & bit[i]) && !(cur.b & bit[j]) && (i == j || scale[i] != scale[j])) {
                        int next_bit = cur.b | bit[i] | bit[j];
                        int next_dist = cur.d + max(scale[i], scale[j]);

                        if (next_dist < dist[next_bit][1]) {
                            pq.push({next_bit, 1, next_dist});
                            dist[next_bit][1] = next_dist;
                        }
                    }
                }
            }

            continue;
        }

        for (int i = 0; i < N; i++) {
            if ((cur.b & bit[i]) > 0) {
                int next_bit = cur.b ^ bit[i];
                int next_dist = cur.d + scale[i];

                if (next_dist < dist[next_bit][0]) {
                    pq.push({next_bit, 0, next_dist});
                    dist[next_bit][0] = next_dist;
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> scale[i];
    }

    scale[N] = INF;

    for (int i = 0; i < N; i++) {
        bit[i] = 1 << i;
    }

    fill(&dist[0][0], &dist[(1 << N) - 1][2], INF);

    dijkstra();

    if (dist[(1 << N) - 1][1] < INF) {
        cout << dist[(1 << N) - 1][1];
    } else {
        cout << -1;
    }
}