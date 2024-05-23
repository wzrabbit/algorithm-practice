#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 10'000'000'000'000'000
typedef long long ll;
using namespace std;

struct Node {
    ll n, d;
    bool b;
};

bool operator<(const Node& a, const Node& b) {
    return a.d > b.d;
}

vector<Node> graph[200001];
ll dist[2][200001];
ll N, K, X, Y;

ll get_dist() {
    priority_queue<Node> pq;
    pq.push({1, 0, false});
    fill(&dist[0][1], &dist[1][N + 1], INF);
    dist[0][1] = 0;

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.b][cur.n]) {
            continue;
        }

        for (size_t i = 0; i < graph[cur.n].size(); i++) {
            Node next_node = graph[cur.n][i];

            if (next_node.b) {
                ll next_dist = max(cur.d, K) + next_node.d;

                if (next_dist < dist[1][next_node.n]) {
                    pq.push({next_node.n, next_dist, true});
                    dist[1][next_node.n] = next_dist;
                }
            } else {
                ll next_dist = cur.d + next_node.d;

                if (next_dist < dist[0][next_node.n]) {
                    pq.push({next_node.n, next_dist, false});
                    dist[0][next_node.n] = next_dist;
                }
            }
        }
    }

    return min(dist[0][N], dist[1][N]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K >> X >> Y;

    for (int i = 1; i <= X; i++) {
        ll u, v, d;
        cin >> u >> v >> d;

        graph[u].push_back({v, d, false});
        graph[v].push_back({u, d, false});
    }

    for (int i = 1; i <= Y; i++) {
        ll u, v, d;
        cin >> u >> v >> d;

        graph[u].push_back({v, d, true});
        graph[v].push_back({u, d, true});
    }

    cout << get_dist();
}
