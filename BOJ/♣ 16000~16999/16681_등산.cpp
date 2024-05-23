#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 1'000'000'000'000'000
typedef long long ll;
using namespace std;

struct Node {
    ll n, d;
};

bool operator<(const Node &a, const Node &b) {
    return a.d > b.d;
}

ll dist_uphill[100001];
ll dist_downhill[100001];
ll height[100001];
vector<Node> graph[100001];
ll N, M, D, E;

void perform_dijkstra(int start_node, ll *dist) {
    priority_queue<Node> pq;
    pq.push({start_node, 0});
    dist[start_node] = 0;

    while (!pq.empty()) {
        Node cur_node = pq.top();
        pq.pop();

        if (cur_node.d > dist[cur_node.n]) {
            continue;
        }

        for (size_t i = 0; i < graph[cur_node.n].size(); i++) {
            Node next_node = graph[cur_node.n][i];

            if (cur_node.d + next_node.d < dist[next_node.n]) {
                dist[next_node.n] = cur_node.d + next_node.d;
                pq.push({next_node.n, cur_node.d + next_node.d});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> D >> E;

    for (int i = 1; i <= N; i++) {
        cin >> height[i];
    }

    for (int i = 1; i <= M; i++) {
        ll u, v, d;
        cin >> u >> v >> d;

        if (height[u] > height[v]) {
            graph[v].push_back({u, d});
        } else if (height[u] < height[v]) {
            graph[u].push_back({v, d});
        }
    }

    fill(dist_uphill + 1, dist_uphill + N + 1, INF);
    fill(dist_downhill + 1, dist_downhill + N + 1, INF);

    perform_dijkstra(1, dist_uphill);
    perform_dijkstra(N, dist_downhill);

    ll best_value = -INF;

    for (int i = 2; i <= N - 1; i++) {
        if (dist_uphill[i] == INF || dist_downhill[i] == INF) {
            continue;
        }

        best_value = max(best_value, height[i] * E - (dist_uphill[i] + dist_downhill[i]) * D);
    }

    if (best_value == -INF) {
        cout << "Impossible";
    } else {
        cout << best_value;
    }
}
