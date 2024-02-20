#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 76'543'210'987
typedef long long ll;
using namespace std;

struct Node {
    ll n, d;
};

bool operator<(const Node &a, const Node &b) {
    return a.d > b.d;
}

ll dist[100001];
vector<Node> graph[100001];
int V, E;

void dijkstra() {
    fill(dist + 1, dist + V + 1, INF);
    dist[1] = 0;
    priority_queue<Node> pq;
    pq.push({1, 0});

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.n]) {
            continue;
        }

        for (size_t i = 0; i < graph[cur.n].size(); i++) {
            Node next_node = graph[cur.n][i];
            ll next_cost = (next_node.d + E - (cur.d % E)) % E + 1;
            ll next_dist = cur.d + next_cost;

            if (next_dist < dist[next_node.n]) {
                dist[next_node.n] = next_dist;
                pq.push({next_node.n, next_dist});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        ll u, v;
        cin >> u >> v;

        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
    }

    dijkstra();

    cout << dist[V];
}
