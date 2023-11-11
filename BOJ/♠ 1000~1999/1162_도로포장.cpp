#include <algorithm>
#include <iostream>
#include <queue>
#define INF 12'345'678'901
typedef long long ll;
using namespace std;

struct Node {
    ll n, d;
};

struct PQData {
    ll n, d, c;
};

bool operator<(const PQData &a, const PQData &b) {
    return a.d < b.d;
}

vector<Node> graph[10001];
ll dist[21][10001];
int V, E, M;

void dijkstra() {
    fill(&dist[0][1], &dist[M][V + 1], INF);
    priority_queue<PQData> pq;
    pq.push({1, 0, 0});
    dist[0][1] = 0;

    while (!pq.empty()) {
        PQData cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.c][cur.n]) {
            continue;
        }

        for (size_t i = 0; i < graph[cur.n].size(); i++) {
            ll next_node = graph[cur.n][i].n;
            ll next_dist = cur.d + graph[cur.n][i].d;

            if (next_dist < dist[cur.c][next_node]) {
                pq.push({next_node, next_dist, cur.c});
                dist[cur.c][next_node] = next_dist;
            }

            if (cur.c < M && cur.d < dist[cur.c + 1][next_node]) {
                pq.push({next_node, cur.d, cur.c + 1});
                dist[cur.c + 1][next_node] = cur.d;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E >> M;

    for (int i = 1; i <= E; i++) {
        ll u, v, d;
        cin >> u >> v >> d;

        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    dijkstra();

    ll best_dist = INF;

    for (int i = 0; i <= M; i++) {
        best_dist = min(dist[i][V], best_dist);
    }

    cout << best_dist;
}