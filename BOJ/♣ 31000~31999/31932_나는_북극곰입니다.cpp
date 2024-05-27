#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 10'000'000'000'000'000
typedef long long ll;
using namespace std;

struct Node {
    ll n, d, t;
};

struct PQData {
    ll n, d;
};

bool operator<(const PQData &a, const PQData &b) {
    return a.d > b.d;
}

ll V, E;
vector<Node> graph[100001];
ll dist[100001];

bool can_go_home(ll start_time) {
    fill(dist + 1, dist + V + 1, INF);
    dist[1] = start_time;
    priority_queue<PQData> pq;
    pq.push({1, start_time});

    while (!pq.empty()) {
        PQData cur = pq.top();
        pq.pop();

        if (cur.d > dist[cur.n]) {
            continue;
        }

        for (size_t i = 0; i < graph[cur.n].size(); i++) {
            Node next_node = graph[cur.n][i];
            ll next_dist = cur.d + next_node.d;

            if (next_dist < dist[next_node.n] && next_dist <= next_node.t) {
                dist[next_node.n] = next_dist;
                pq.push({next_node.n, next_dist});
            }
        }
    }

    return dist[V] < INF;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E;

    for (int i = 1; i <= E; i++) {
        ll u, v, d, t;
        cin >> u >> v >> d >> t;

        graph[u].push_back({v, d, t});
        graph[v].push_back({u, d, t});
    }

    ll start = 0;
    ll end = 1'000'000'000;
    ll mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (can_go_home(mid)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << end;
}
