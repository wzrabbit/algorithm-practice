#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 9'876'543'210
typedef long long ll;
using namespace std;

struct Node {
    ll n, d;
    bool f;
};

bool operator<(const Node& a, const Node& b) {
    return a.d > b.d;
}

vector<Node> graph[50000];
ll dist[2][50000];
int V, E, F, start_node, end_node;

void dijkstra() {
    priority_queue<Node> pq;
    fill(&dist[0][0], &dist[1][V], INF);
    pq.push({start_node, 0, false});
    dist[0][start_node] = 0;

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.f][cur.n]) {
            continue;
        }

        for (size_t i = 0; i < graph[cur.n].size(); i++) {
            ll next_node = graph[cur.n][i].n;
            ll next_dist = cur.d + graph[cur.n][i].d;
            bool is_flight = graph[cur.n][i].f;

            if (is_flight && !cur.f && next_dist < dist[1][next_node]) {
                pq.push({next_node, next_dist, true});
                dist[1][next_node] = next_dist;
            }

            if (!is_flight && next_dist < dist[cur.f][next_node]) {
                pq.push({next_node, next_dist, cur.f});
                dist[cur.f][next_node] = next_dist;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E >> F >> start_node >> end_node;

    for (int i = 1; i <= E; i++) {
        int u, v, d;
        cin >> u >> v >> d;

        graph[u].push_back({v, d, false});
        graph[v].push_back({u, d, false});
    }

    for (int i = 1; i <= F; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back({v, 0, true});
    }

    dijkstra();

    cout << min(dist[0][end_node], dist[1][end_node]);
}
