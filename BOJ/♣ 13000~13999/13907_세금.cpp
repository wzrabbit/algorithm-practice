#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 400000000
using namespace std;

struct loc {
    int v, d;
};

struct p_loc {
    int v, d, n;
};

bool operator<(p_loc a, p_loc b) {
    return a.d > b.d;
}

vector<loc> graph[1002];
int dist[1002][1002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, K, S, E;
    cin >> N >> M >> K >> S >> E;

    for (int i = 1; i <= M; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        graph[s].push_back({e, d});
        graph[e].push_back({s, d});
    }

    priority_queue<p_loc> pq;
    pq.push({S, 0, 0});
    fill(&dist[1][0], &dist[N][N + 1], INF);
    dist[S][0] = 0;

    while (pq.size()) {
        p_loc cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.v][cur.n]) continue;

        for (size_t i = 0; i < graph[cur.v].size(); i++) {
            loc nxt = graph[cur.v][i];

            if (cur.d + nxt.d < dist[nxt.v][cur.n + 1] && cur.n + 1 < N) {
                dist[nxt.v][cur.n + 1] = cur.d + nxt.d;
                pq.push({nxt.v, cur.d + nxt.d, cur.n + 1});
            }
        }
    }

    vector<int> increased;
    increased.push_back(0);
    for (int i = 1; i <= K; i++) {
        int x;
        cin >> x;
        increased.push_back(increased.back() + x);
    }

    for (int i = 0; i <= K; i++) {
        int best = INF;
        for (int j = 1; j <= N; j++) {
            best = min(best, dist[E][j] + j * increased[i]);
        }
        cout << best << '\n';
    }
}